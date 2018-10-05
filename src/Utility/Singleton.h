#pragma once

#ifdef _DEBUG
#pragma comment(lib, "Utility_d.lib")
#else
#pragma comment(lib, "Utility.lib")
#endif // _DEBUG

#ifndef SINGLETON

/// <summary>
/// �V���O���g���̐ݒ�
/// </summary>
/// <param name="_Class_">�N���X��</param>
#define SINGLETON(_Class_) \
public: \
friend class CreaDXTKLib::Utility::Singleton<_Class_>; \
protected: \
inline _Class_() { } \
inline ~_Class_() { }

#endif // !SINGLETON

namespace CreaDXTKLib
{
namespace Utility
{
    /// <summary>
    /// �V���O���g���̊��N���X
    /// </summary>
    template<class T>
    class Singleton
    {
    private:

        inline Singleton(const Singleton&) { } // �R�s�[�R���X�g���N�^�̎g�p�֎~

        inline void operator = (const Singleton& obj) { } // ������Z�q�̎g�p�֎~

    protected:

        inline Singleton() { } // �O���ł̃C���X�^���X�������֎~
        inline virtual ~Singleton() { }

    public:

        /// <summary>
        /// �C���X�^���X���擾
        /// </summary>
        /// <returns>�C���X�^���X</returns>
        static T & Instance();

    };

} // Utility
} // CreaDXTKLib

// ��`�t�@�C�����C���N���[�h
#include "SingletonDetail.h"