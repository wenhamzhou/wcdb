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

#include <WCDB/statement_trigger.hpp>

namespace WCDB {
    
StatementTrigger &StatementTrigger::createTriggerWithNew(const std::string triggerCallBackName,  const std::list<const std::string> &columnNameList)
{
    m_description.append("SELECT " + triggerCallBackName+"(");
    m_description.append("NEW.rowid");
    for (const std::string &t : columnNameList) {
        m_description.append(",NEW." + t);
    }
    m_description.append(");");
    return *this;
}

StatementTrigger &StatementTrigger::createTriggerWithOld(const std::string triggerCallBackName,  const std::list<const std::string> &columnNameList)
{
    m_description.append("SELECT " + triggerCallBackName+"(");
    m_description.append("OLD.rowid");
    for (const std::string &t : columnNameList) {
        m_description.append(",OLD." + t);
    }
    m_description.append(");");
    return *this;
}

Statement::Type StatementTrigger::getStatementType() const
{
    return Statement::Type::Trigger;
}

} //namespace WCDB
