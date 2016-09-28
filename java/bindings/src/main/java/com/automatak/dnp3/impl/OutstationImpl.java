/**
 * Copyright 2013 Automatak, LLC
 *
 * Licensed to Automatak, LLC (www.automatak.com) under one or more
 * contributor license agreements. See the NOTICE file distributed with this
 * work for additional information regarding copyright ownership. Automatak, LLC
 * licenses this file to you under the Apache License Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0.html
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
package com.automatak.dnp3.impl;

import com.automatak.dnp3.*;

import java.time.Duration;
import java.util.Arrays;
import java.util.concurrent.CompletableFuture;

class OutstationImpl implements Outstation {

    private long nativePointer;

    @Override
    public synchronized void enable()
    {
        if(nativePointer != 0) {
            enable_native(nativePointer);
        }
    }

    @Override
    public synchronized void disable()
    {
        if(nativePointer != 0) {
            disable_native(nativePointer);
        }
    }

    @Override
    public synchronized void shutdown()
    {
        if(nativePointer != 0) {
            shutdown_native(nativePointer);
            nativePointer = 0;
        }
    }

    @Override
    public void load(ChangeSet changeSet)
    {

    }

    private native void enable_native(long nativePointer);
    private native void disable_native(long nativePointer);
    private native void shutdown_native(long nativePointer);
}
