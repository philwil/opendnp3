//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2013-2019 Automatak, LLC
// 
// Licensed to Green Energy Corp (www.greenenergycorp.com) and Automatak
// LLC (www.automatak.com) under one or more contributor license agreements.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership. Green Energy Corp and Automatak LLC license
// this file to you under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may obtain
// a copy of the License at:
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "JNIIterator.h"

namespace jni
{
    namespace cache
    {
        bool Iterator::init(JNIEnv* env)
        {
            auto clazzTemp = env->FindClass("Ljava/util/Iterator;");
            this->clazz = (jclass) env->NewGlobalRef(clazzTemp);
            env->DeleteLocalRef(clazzTemp);

            this->hasNextMethod = env->GetMethodID(this->clazz, "hasNext", "()Z");
            if(!this->hasNextMethod) return false;

            this->nextMethod = env->GetMethodID(this->clazz, "next", "()Ljava/lang/Object;");
            if(!this->nextMethod) return false;

            return true;
        }

        void Iterator::cleanup(JNIEnv* env)
        {
            env->DeleteGlobalRef(this->clazz);
        }

        jboolean Iterator::hasNext(JNIEnv* env, jobject instance)
        {
            return env->CallBooleanMethod(instance, this->hasNextMethod);
        }

        LocalRef<jobject> Iterator::next(JNIEnv* env, jobject instance)
        {
            return LocalRef<jobject>(env, env->CallObjectMethod(instance, this->nextMethod));
        }
    }
}
