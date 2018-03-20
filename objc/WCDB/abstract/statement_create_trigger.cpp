/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <WCDB/statement_create_trigger.hpp>

const char * TriggerDescriptions[] = { "",
    "BEFORE INSERT ",
    "AFTER INSERT ",
    "BEFORE UPDATE ",
    "AFTER UPDATE ",
    "BEFORE DELETE ",
    "AFTER DELETE ",
    "INSTEAD OF INSERT ",
    "INSTEAD OF DELETE ",
    "INSTEAD OF UPDATE " };

namespace WCDB {

Statement::Type StatementCreateTrigger::getStatementType() const
{
    return Statement::Type::CreateTrigger;
}
    
std::string StatementCreateTrigger::getDescriptionOfType(StatementCreateTrigger::Type type){
    unsigned int typeIntValue = (unsigned int)type;
    if(typeIntValue <= 9){
        return TriggerDescriptions[typeIntValue];
    }
    return "";
}

} //namespace WCDB
