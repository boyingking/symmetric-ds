/**
 * Licensed to JumpMind Inc under one or more contributor
 * license agreements.  See the NOTICE file distributed
 * with this work for additional information regarding
 * copyright ownership.  JumpMind Inc licenses this file
 * to you under the GNU General Public License, version 3.0 (GPLv3)
 * (the "License"); you may not use this file except in compliance
 * with the License.
 *
 * You should have received a copy of the GNU General Public License,
 * version 3.0 (GPLv3) along with this library; if not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#ifndef SYM_TABLE_H
#define SYM_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/List.h"
#include "util/StringBuilder.h"
#include "db/model/Column.h"

typedef struct SymTable {
    char *catalog;
    char *schema;
    char *name;
    SymList *columns;
    struct SymTable * (*copy_and_filter_columns)(struct SymTable *this, struct SymTable *source, unsigned short setPrimaryKeys);
    void (*copy_column_types_from)(struct SymTable *this, struct SymTable *source);
    SymColumn * (*find_column)(struct SymTable *this, char *name, unsigned short caseSensitive);
    char * (*to_string)(struct SymTable *this);
    void (*destroy)(struct SymTable *this);
} SymTable;

SymTable * SymTable_new(SymTable *this);

SymTable * SymTable_new_with_name(SymTable *this, char *name);

SymTable * SymTable_new_with_fullname(SymTable *this, char *catalog, char *schema, char *name);

char * SymTable_get_full_table_name(SymTable *this, char *delimiterToken, char *catalogSeparator, char *schemaSeparator);

#endif
