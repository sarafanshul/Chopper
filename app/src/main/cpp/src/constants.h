//
// Created by Anshul Saraf on 28/06/22.
//

#ifndef CHOPPER_CONSTANTS_H
#define CHOPPER_CONSTANTS_H

#include "opencv2/core/version.hpp"
#include <jni.h>


namespace ChopperJNI{

    static jfloat JniVersion(JNIEnv *env, jobject object) {
        return 1.4;
    }

    static jstring OpenCVVersion(JNIEnv *env, jobject object){
        return env->NewStringUTF(CV_VERSION);
    }

    static const char *constants = "com/projectdelta/chopper/util/Constants";

    static JNINativeMethod constants_methods[] = {
            {"nativeGetJniVersion", "()F", (void *) JniVersion},
            {"nativeGetOpenCVVersion", "()Ljava/lang/String;", (void *) OpenCVVersion}
    };
}

#endif //CHOPPER_CONSTANTS_H
