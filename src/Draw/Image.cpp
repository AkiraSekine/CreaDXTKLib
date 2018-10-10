#include "Image.h"

#include "../Utility/Debug.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace Microsoft::WRL;

using namespace CreaDXTKLib::Utility;

namespace CreaDXTKLib
{
namespace Draw
{
    map<wstring, Image::ImageData> Image::m_imageData =
        map<wstring, Image::ImageData>();

    unique_ptr<SpriteBatch> Image::m_spriteBatch;

    ComPtr<ID3D11Device1> Image::m_device;

    void Image::Initialize(ComPtr<ID3D11DeviceContext1> _context, ComPtr<ID3D11Device1>& _device)
    {
        static bool initialized = false;

        if (initialized)
        {
            Debug::Log(L"Do not use.\n");
            throw exception("Do not use.\n");
        }

        initialized = true;

        m_spriteBatch = make_unique<SpriteBatch>(_context.Get());

        m_device = _device;
    }

    void Image::OnEnd()
    {
        static bool initialized = false;

        if (initialized)
        {
            Debug::Log(L"Do not use.\n");
            throw exception("Do not use.\n");
        }

        initialized = true;

        for (auto i = m_imageData.begin(); i != m_imageData.end(); i++)
        {
            i->second.m_texture.Reset();
        }

        m_imageData.clear();
    }

    void Image::Load(wstring _fileName, wstring _name)
    {
        for (auto i = m_imageData.begin(); i != m_imageData.end(); i++)
        {
            if (i->first.compare(_name) == 0)
            {
                Debug::Log(L"%s has already been loaded.\n", _name);
                throw invalid_argument("");
            }
        }

        m_imageData.insert(make_pair(_name, ImageData()));

        ComPtr<ID3D11Resource> resource;
        DX::ThrowIfFailed(
            CreateWICTextureFromFile(m_device.Get(), _fileName.c_str(),
            resource.GetAddressOf(),
            m_imageData.at(_name).m_texture.ReleaseAndGetAddressOf()));

        ComPtr<ID3D11Texture2D> tex;
        DX::ThrowIfFailed(resource.As(&tex));

        CD3D11_TEXTURE2D_DESC texDesc;
        tex->GetDesc(&texDesc);

        m_imageData.at(_name).m_size = Vector2((float)texDesc.Width, (float)texDesc.Height);
    }

    void Image::Erase(wstring _name)
    {
        try
        {
            m_imageData.at(_name).m_texture.Reset();
            m_imageData.erase(_name);
        }
        catch (const out_of_range&)
        {
            Debug::Log(L"%s is not loaded.\n", _name);
            throw out_of_range("");
        }
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position)
    {
        Draw(_name, _position, Colors::White);
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const float _rotation,
        const Vector2 _pivot)
    {
        Draw(_name, _position, _rotation, Colors::White, _pivot);
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const float _rotation,
        const Vector2 _scale,
        const Vector2 _pivot)
    {
        Draw(_name, _position, _rotation, _scale, Colors::White, _pivot);
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const float _rotation,
        const Vector2 _scale,
        const RECT _rect,
        const Vector2 _pivot)
    {
        Draw(_name,
            _position,
            _rotation,
            _scale,
            _rect,
            Colors::White,
            _pivot);
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const FXMVECTOR _color)
    {
        Draw(_name, _position, 0.f, _color, Vector2::Zero);
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const float _rotation,
        const FXMVECTOR _color,
        const Vector2 _pivot)
    {
        Draw(_name, _position, _rotation, Vector2::One, _color, _pivot);
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const float _rotation,
        const Vector2 _scale,
        const FXMVECTOR _color,
        const Vector2 _pivot)
    {
        Vector2 size = m_imageData.at(_name).m_size;
        RECT rect = { 0, 0, (long)size.x, (long)size.y };

        Draw(_name, _position, _rotation, _scale, rect, _color, _pivot);
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const float _rotation,
        const Vector2 _scale,
        const RECT _rect,
        const FXMVECTOR _color,
        const Vector2 _pivot)
    {
        m_spriteBatch->Begin();

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

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const XMVECTORF32 _color)
    {
        Draw(_name, _position, 0.f, _color, Vector2::Zero);
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const float _rotation,
        const XMVECTORF32 _color,
        const Vector2 _pivot)
    {
        Draw(_name, _position, _rotation, Vector2::One, _color, _pivot);
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const float _rotation,
        const Vector2 _scale,
        const XMVECTORF32 _color,
        const Vector2 _pivot)
    {
        Vector2 size = m_imageData.at(_name).m_size;
        RECT rect = { 0, 0, (long)size.x, (long)size.y };

        Draw(_name, _position, _rotation, _scale, rect, _color, _pivot);
    }

    void Image::Draw(const wstring _name,
        const Vector2 _position,
        const float _rotation,
        const Vector2 _scale,
        const RECT _rect,
        const XMVECTORF32 _color,
        const Vector2 _pivot)
    {
        m_spriteBatch->Begin();

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
} // Draw
} // CreaDXTKLib