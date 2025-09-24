#ifndef IDB_CONNECTION_H
#define IDB_CONNECTION_H

#include <string>

// Интерфейс для работы с базой данных
class IDBConnection {
public:
    virtual ~IDBConnection() = default;

    // Открытие соединения с базой
    virtual bool open() = 0;

    // Закрытие соединения
    virtual void close() = 0;

    // Выполнение SQL-запроса
    virtual std::string execQuery(const std::string& query) = 0;
};

#endif 