#ifndef WTF_PassRefPtr_h
#define WTF_PassRefPtr_h


template<typename T> class RefPtr;
template<typename T> class PassRefPtr;

template<typename T> PassRefPtr<T> adoptRef(T*);

#define ALWAYS_INLINE inline
#define REF_DEREF_INLINE inline

template<typename T> REF_DEREF_INLINE void refIfNotNull(T* ptr)
{
    if (ptr != 0)
        ptr->ref();
}

template<typename T> REF_DEREF_INLINE void derefIfNotNull(T* ptr)
{
    if (ptr != 0){
        cout << "ptr not 0"<< endl;
        ptr->deref();
    } else
        cout << "ptr 0"<< endl;
}

template<typename T> class PassRefPtr {
    public:
        PassRefPtr() : m_ptr(0) { }
        PassRefPtr(T* ptr) : m_ptr(ptr) { refIfNotNull(ptr); }

        T* leakRef() const;

    friend PassRefPtr adoptRef<T>(T*);

    private:
        // adopting constructor
        PassRefPtr(T* ptr, bool) : m_ptr(ptr) { }

        mutable T* m_ptr;
};

template<typename T> inline PassRefPtr<T> adoptRef(T* p)
{
    //adopted(p);
    return PassRefPtr<T>(p, true);
}

template<typename T> inline T* PassRefPtr<T>::leakRef() const
{
    T* ptr = m_ptr;
    m_ptr = 0;
    return ptr;
}

#endif
