extern "C"
{

void* __dso_handle = nullptr;

int 
__cxa_guard_acquire (void*)
{
    // ...
}

int 
__cxa_guard_release (void*)
{
    // ...
}

int 
__aeabi_atexit (void* /*object*/, 
                void (*/*destructor*/)(void*), 
                void* /*dso_handle*/) 
{
    return 0; 
} 

void 
__cxa_pure_virtual () 
{ 
    while (true) {
        // ...
    } 
}

};

void 
operator delete (void*) 
{
    // ... 
}
