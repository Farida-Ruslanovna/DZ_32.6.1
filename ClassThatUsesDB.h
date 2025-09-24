#ifndef CLASS_THAT_USES_DB_H
#define CLASS_THAT_USES_DB_H

#include "IDBConnection.h"


class ClassThatUsesDB {
public:
    // Конструктор с внедрением зависимости (интерфейса)
    explicit ClassThatUsesDB(IDBConnection* connection)
        : connection_(connection) {
    }

    // Открытие соединения
    bool openConnection() {
        return connection_->open();
    }

    // Использование соединения для выполнения запроса
    std::string useConnection(const std::string& query) {
        return connection_->execQuery(query);
    }

    // Закрытие соединения
    void closeConnection() {
        connection_->close();
    }

private:
    IDBConnection* connection_;
};

#endif 