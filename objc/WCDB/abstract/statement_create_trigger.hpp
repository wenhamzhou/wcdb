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

#ifndef statement_create_trigger_hpp
#define statement_create_trigger_hpp

#include <WCDB/declare.hpp>
#include <WCDB/statement.hpp>
#include <WCDB/expr.hpp>

namespace WCDB {

class StatementCreateTrigger : public Statement {
public:
    enum class Type : int {
        None = 0,
        BeforeInsert,
        AfterInsert,
        BeforeUpdate,
        AfterUpdate,
        BeforeDelete,
        AfterDelete,
        InsteadOfInsert,
        InsteadOfDelete,
        InsteadOfUpdate,
    };
    template <typename T = ColumnDef>
    typename std::enable_if<std::is_base_of<ColumnDef, T>::value,
                            StatementCreateTrigger &>::type
    create(const std::string &name,
           StatementCreateTrigger::Type type,
           const std::string &table,
           const Expr &when,
           const Statement &triggerStatement,
           bool ifNotExists = true)
    {
        m_description.append("CREATE TRIGGER ");
        if (ifNotExists) {
            m_description.append("IF NOT EXISTS ");
        }
        m_description.append(name + " ");
        m_description.append(this->getDescriptionOfType(type));
        m_description.append("ON " + table + " ");
        if(!when.isEmpty()){
           m_description.append("WHEN " + when.getDescription() + " ");
        }
        m_description.append("BEGIN ");
        m_description.append(triggerStatement.getDescription()+ " ");
        m_description.append("END;");
        return *this;
    }

    virtual Statement::Type getStatementType() const override;
    std::string getDescriptionOfType(StatementCreateTrigger::Type type);
};

} //namespace WCDB

#endif /* statement_create_trigger_hpp */
