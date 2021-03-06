/*
 * Copyright 2013-2019 Automatak, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Automatak
 * LLC (www.automatak.com) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Automatak LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ASIODNP3_UPDATES_H
#define ASIODNP3_UPDATES_H

#include "opendnp3/outstation/IUpdateHandler.h"

#include <functional>
#include <memory>
#include <vector>

namespace asiodnp3
{

typedef std::function<void(opendnp3::IUpdateHandler&)> update_func_t;
typedef std::vector<update_func_t> shared_updates_t;

class Updates
{
    friend class UpdateBuilder;

public:
    void Apply(opendnp3::IUpdateHandler& handler) const
    {
        if (!updates)
            return;

        for (auto& update : *updates)
        {
            update(handler);
        }
    }

    bool IsEmpty() const
    {
        return updates ? updates->empty() : true;
    }

private:
    Updates(std::shared_ptr<shared_updates_t> updates) : updates(std::move(updates)) {}

    const std::shared_ptr<shared_updates_t> updates;
};

} // namespace asiodnp3

#endif
