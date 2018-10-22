#pragma once

#include "../Default/pch.h"
#include "../Utility/Singleton.h"
#include "../Math/Vector2.h"

#include <string>
#include <map>

namespace CreaDXTKLib
{
    namespace Utility
    {
        template <class T> class Singleton;
    }

namespace Draw
{
    class Text final : public Utility::Singleton<Text>
    {
        SINGLETON(Text)

    public:

        void Load(const std::wstring& _key, const std::wstring& _fileName);

        void Draw(const std::wstring& _key, const Math::Vector2& _position, const std::wstring _text, ...);

        void Initialize(Microsoft::WRL::ComPtr<ID3D11Device1> _device, Microsoft::WRL::ComPtr<ID3D11DeviceContext1> _context);
        void OnEnd();

    private:

        Microsoft::WRL::ComPtr<ID3D11Device1> m_device;

        std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;

        std::map<std::wstring, DirectX::SpriteFont*> m_fonts = std::map<std::wstring, DirectX::SpriteFont*>();

    };
}
}