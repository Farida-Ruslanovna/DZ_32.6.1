// DZ_32.6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ClassThatUsesDB.h"
#include "MockDBConnection.h"

// Тест: проверка успешного открытия соединения
TEST(ClassThatUsesDBTest, OpenConnectionSuccess) {
    MockDBConnection mock_db;

    // Ожидаем вызов метода open один раз и возвращаем true
    EXPECT_CALL(mock_db, open())
        .Times(1)
        .WillOnce(::testing::Return(true));

    ClassThatUsesDB obj(&mock_db);
    // Проверка, что метод openConnection возвращает true
    EXPECT_TRUE(obj.openConnection());
}

// Тест: проверка выполнения метода useConnection
TEST(ClassThatUsesDBTest, UseConnectionReturnsExpectedResult) {
    MockDBConnection mock_db;
    std::string query = "SELECT * FROM table";
    std::string expected_result = "mocked result";

    // Ожидаем вызов execQuery с указанным запросом и возвращаем фиктивный результат
    EXPECT_CALL(mock_db, execQuery(query))
        .Times(1)
        .WillOnce(::testing::Return(expected_result));

    ClassThatUsesDB obj(&mock_db);
    // Проверяем, что результат соответствует ожидаемому
    std::string result = obj.useConnection(query);
    EXPECT_EQ(result, expected_result);
}

// Тест: проверка вызова метода close
TEST(ClassThatUsesDBTest, CloseConnectionCalled) {
    MockDBConnection mock_db;

    // Ожидаем вызов метода close один раз
    EXPECT_CALL(mock_db, close())
        .Times(1);

    ClassThatUsesDB obj(&mock_db);
    // Вызов метода закрытия соединения
    obj.closeConnection();
}