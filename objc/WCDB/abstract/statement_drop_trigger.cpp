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
#include <WCDB/statement_drop_trigger.hpp>

namespace WCDB {
    
StatementDropTrigger StatementDropTrigger::drop(const std::string &name, bool ifExists)
{
    m_description.append("DROP TRIGGER ");
    if (ifExists) {
        m_description.append("IF EXISTS ");
    }
    m_description.append(name);
    return *this;
}

Statement::Type StatementDropTrigger::getStatementType() const
{
    return Statement::Type::DropTrigger;
}

} //namespace WCDB
