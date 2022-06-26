//
// Created by win10 on 26-06-2022.
//

#ifndef CHOPPER_CHOPPER_JNI_H
#define CHOPPER_CHOPPER_JNI_H

#include <jni.h>
#include <string>
#include "logger.h"

#define SIZE(X) sizeof(X) / sizeof(X[0])


typedef union {
    JNIEnv *env;
    void *venv;
} UnionJNIEnvToVoid;


static jfloat JniVersion() {
    return 1.4;
}

static const char *constants = "com/projectdelta/chopper/util/Constants";
static JNINativeMethod constants_methods[] = {
    {"nativeGetJniVersion", "()F", (void *) JniVersion},
};


/*
 * Register several native methods for one class.
 */
static int registerNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *gMethods,
                                 int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        ALOGE("Native registration unable to find class '%s'", className);
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        ALOGE("RegisterNatives failed for '%s'", className);
        return JNI_FALSE;
    }
    return JNI_TRUE;
}


/*
 * Register native methods for all classes we know about.
 *
 * returns JNI_TRUE on success.
 */
static int registerNatives(JNIEnv *env) {
    if (!registerNativeMethods(env, constants, constants_methods, SIZE(constants_methods))) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}


/*
 * This is called by the VM when the shared library is first loaded.
 */
jint JNI_OnLoad(JavaVM *vm, void *reserved);

#endif //CHOPPER_CHOPPER_JNI_H