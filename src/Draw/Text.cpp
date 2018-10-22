#include "Text.h"

using namespace std;
using namespace Microsoft::WRL;
using namespace DirectX;
using namespace CreaDXTKLib::Math;

namespace CreaDXTKLib
{
namespace Draw
{
    void Text::Load(const wstring& _key, const wstring& _fileName)
    {
        m_fonts.insert(make_pair(_key, new SpriteFont(m_device.Get(), _fileName.c_str())));
    }

    void Text::Draw(const wstring & _key, const Vector2 & _position, const wstring _text, ...)
    {
        va_list arg;
        wchar_t newStr[512];

        va_start(arg, _text);
        vswprintf_s(newStr, _text.c_str(), arg);
        va_end(arg);

        m_spriteBatch->Begin();

        m_fonts.at(_key)->DrawString(m_spriteBatch.get(), newStr, _position);

        m_spriteBatch->End();
    }

    void Text::Initialize(ComPtr<ID3D11Device1> _device, ComPtr<ID3D11DeviceContext1> _context)
    {
        m_device = _device.Get();
        m_spriteBatch = make_unique<SpriteBatch>(_context.Get());
    }

    void Text::OnEnd()
    {
        for (auto i = m_fonts.begin(); i != m_fonts.end(); i++)
        {
            delete i->second;
        }

        m_fonts.clear();
    }
}
}