#include "Draw/Image.h"

#include "Utility/Debug.h"
#include "Draw/Text.h"

using namespace std;
using namespace DirectX;
using namespace Microsoft::WRL;

using namespace CreaDXTKLib::Utility;
using namespace CreaDXTKLib::Math;

namespace CreaDXTKLib
{
namespace Draw
{

    void Image::Initialize(ComPtr<ID3D11DeviceContext1> _context, ComPtr<ID3D11Device1>& _device)
    {
        // ������Ă΂�Ă�����throw����
        static bool initialized = false;

        if (initialized)
        {
            Debug::Log(L"Do not use.\n");
            throw exception("Do not use.\n");
        }

        initialized = true;

        m_spriteBatch = make_unique<SpriteBatch>(_context.Get());

        m_device = _device;

        m_states = make_unique<CommonStates>(m_device.Get());

        Text::Instance().Initialize(_device, _context);
    }

    void Image::OnEnd()
    {
        // ������Ă΂�Ă�����throw����
        static bool initialized = false;

        if (initialized)
        {
            Debug::Log(L"Do not use.\n");
            throw exception("Do not use.\n");
        }

        initialized = true;

        // m_texture����ɂ���
        for (auto i = m_imageData.begin(); i != m_imageData.end(); i++)
        {
            i->second.m_texture.Reset();
        }

        m_imageData.clear();

        m_states.reset();
    }

    void Image::Load(const wstring& _fileName, const wstring& _name)
    {
        // �������O�����悤�Ƃ�����throw����
        for (auto i = m_imageData.begin(); i != m_imageData.end(); i++)
        {
            if (i->first.compare(_name) == 0)
            {
                Debug::Log(L"%s has already been loaded.\n", _name);
                throw invalid_argument("");
            }
        }

        // �f�[�^��ۑ�����
        m_imageData.insert(make_pair(_name, ImageData()));

        // �摜��ǂݍ���
        ComPtr<ID3D11Resource> resource;
        DX::ThrowIfFailed(
            CreateWICTextureFromFile(m_device.Get(), _fileName.c_str(),
            resource.GetAddressOf(),
            m_imageData.at(_name).m_texture.ReleaseAndGetAddressOf()));

        ComPtr<ID3D11Texture2D> tex;
        DX::ThrowIfFailed(resource.As(&tex));

        CD3D11_TEXTURE2D_DESC texDesc;
        tex->GetDesc(&texDesc);

        // �T�C�Y��ۑ�����
        m_imageData.at(_name).m_size = Vector2((float)texDesc.Width, (float)texDesc.Height);
    }

    void Image::Erase(const wstring& _name)
    {
        try
        {
            // �ǂݍ��񂾉摜��j������
            m_imageData.at(_name).m_texture.Reset();
            m_imageData.erase(_name);
        }
        // _name�̃f�[�^���Ȃ�������throw����
        catch (const out_of_range&)
        {
            Debug::Log(L"%s is not loaded.\n", _name);
            throw out_of_range("");
        }
    }

    Vector2 Image::GetImageSize(const std::wstring & _name)
    {
        return m_imageData.at(_name).m_size;
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name, _position, Colors::White);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const float _rotation)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name, _position, _rotation, Colors::White);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const float _rotation,
        const Vector2& _scale,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name, _position, _rotation, _scale, Colors::White, _pivot);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const float _rotation,
        const Vector2& _scale,
        const RECT& _rect,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name,
            _position,
            _rotation,
            _scale,
            _rect,
            Colors::White,
            _pivot);
    }

    void Image::Draw(const std::wstring& _name,
        const Transform2D& _transform,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name,
            _transform.Position(),
            _transform.Rotation(),
            _transform.Scale(),
            Colors::White, _pivot);
    }

    void Image::Draw(const wstring& _name,
        const Transform2D& _transform,
        const RECT& _rect,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name,
            _transform.Position(),
            _transform.Rotation(),
            _transform.Scale(),
            _rect,
            _pivot);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const FXMVECTOR& _color)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name, _position, 0.f, _color, Vector2::zero);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const float _rotation,
        const FXMVECTOR& _color,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name, _position, _rotation, Vector2::one, _color, _pivot);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const float _rotation,
        const Vector2& _scale,
        const FXMVECTOR& _color,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Vector2 size = m_imageData.at(_name).m_size;
        RECT rect = { 0, 0, (long)size.x, (long)size.y };

        Draw(_name, _position, _rotation, _scale, rect, _color, _pivot);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const float _rotation,
        const Vector2& _scale,
        const RECT& _rect,
        const FXMVECTOR& _color,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        m_spriteBatch->Begin(SpriteSortMode_Deferred,
            m_states->NonPremultiplied());

        // �摜��`�悷��
        m_spriteBatch->Draw(
            m_imageData.at(_name).m_texture.Get(),
            _position,
            &_rect,
            _color,
            _rotation,
            _pivot,
            _scale);

        m_spriteBatch->End();
    }

    void Image::Draw(const wstring& _name,
        const Transform2D& _transform,
        const FXMVECTOR& _color,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name,
            _transform.Position(),
            _transform.Rotation(),
            _transform.Scale(),
            _color,
            _pivot);
    }

    void Image::Draw(const wstring& _name,
        const Transform2D& _transform,
        const RECT& _rect,
        const FXMVECTOR& _color,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name,
            _transform.Position(),
            _transform.Rotation(),
            _transform.Scale(),
            _rect,
            _color,
            _pivot);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const XMVECTORF32& _color)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name, _position, 0.f, _color, Vector2::zero);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const float _rotation,
        const XMVECTORF32& _color,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name, _position, _rotation, Vector2::one, _color, _pivot);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const float _rotation,
        const Vector2& _scale,
        const XMVECTORF32& _color,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Vector2 size = m_imageData.at(_name).m_size;
        RECT rect = { 0, 0, (long)size.x, (long)size.y };

        Draw(_name, _position, _rotation, _scale, rect, _color, _pivot);
    }

    void Image::Draw(const wstring& _name,
        const Transform2D& _transform,
        const XMVECTORF32& _color,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name,
            _transform.Position(),
            _transform.Rotation(),
            _transform.Scale(),
            _color,
            _pivot);
    }

    void Image::Draw(const wstring& _name,
        const Vector2& _position,
        const float _rotation,
        const Vector2& _scale,
        const RECT& _rect,
        const XMVECTORF32& _color,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        m_spriteBatch->Begin(SpriteSortMode_Deferred,
            m_states->NonPremultiplied());

        // �摜��`�悷��
        m_spriteBatch->Draw(
            m_imageData.at(_name).m_texture.Get(),
            _position,
            &_rect,
            _color,
            _rotation,
            _pivot,
            _scale);

        m_spriteBatch->End();
    }
    void Image::Draw(const wstring& _name,
        const Transform2D& _transform,
        const RECT& _rect,
        const XMVECTORF32& _color,
        const Vector2& _pivot)
    {
        // �n���h��������Ȃ�I��
        if (_name.compare(L"") == 0)
        {
            return;
        }

        Draw(_name,
            _transform.Position(),
            _transform.Rotation(),
            _transform.Scale(),
            _rect,
            _color,
            _pivot);
    }
} // Draw
} // CreaDXTKLib
