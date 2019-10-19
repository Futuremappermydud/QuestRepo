#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <wchar.h>
#include <unistd.h>
#include <dirent.h>
#include <linux/limits.h>
#include <sys/sendfile.h>
#include <sys/stat.h>

#include "../beatsaber-hook/shared/inline-hook/inlineHook.h"

#define LOG_LEVEL CRITICAL | ERROR | WARNING | INFO | DEBUG

#define MOD_ID "QParticles"
#define VERSION "0.0.1"

#include "../beatsaber-hook/shared/utils/utils.h"
#include "../beatsaber-hook/shared/utils/typedefs.h"

#define Unity_Emit_Offset 0x17EB0C4
#define ParametricBoxFakeGlowControllerOnEnable_Offset 0x97D408 

//This disabled the particles! 

MAKE_HOOK(Unity_Emit, Unity_Emit_Offset, void, void *self, void *emitParams, int count){
    count = 0;
    Unity_Emit(self, emitParams, count);
    log(DEBUG, "[QP] Hit");
}

//This disables the glow effect on Walls!

MAKE_HOOK(ParametricBoxFakeGlowControllerOnEnable, ParametricBoxFakeGlowControllerOnEnable_Offset, void, Il2CppObject* self){
    il2cpp_functions::Init();
    auto klass = il2cpp_functions::object_get_class(self);
    auto method = il2cpp_functions::class_get_method_from_name(klass, "OnDisable", 0);
    auto run = il2cpp_utils::RunMethod(self, method);
    log(DEBUG, "[QP] Glow on walls are disabled!");
}

__attribute__((constructor)) void lib_main()
{
    #ifdef __aarch64__
    log(INFO, "Is 64 bit!");
    #endif
    log(DEBUG, "Installing QParticles");
    INSTALL_HOOK(Unity_Emit);
    INSTALL_HOOK(ParametricBoxFakeGlowControllerOnEnable);
    log(DEBUG, "Successfully installed QParticles!");
}


