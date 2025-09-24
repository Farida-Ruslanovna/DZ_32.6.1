#ifndef MOCK_DB_CONNECTION_H
#define MOCK_DB_CONNECTION_H

#include "gmock/gmock.h"
#include "IDBConnection.h"

// Мок-класс для интерфейса IDBConnection
class MockDBConnection : public IDBConnection {
public:
    
    MOCK_METHOD(bool, open, (), (override));
    MOCK_METHOD(void, close, (), (override));
    MOCK_METHOD(std::string, execQuery, (const std::string& query), (override));
};

#endif 