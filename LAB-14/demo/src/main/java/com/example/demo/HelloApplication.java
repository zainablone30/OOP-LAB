package com.example.demo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class HelloApplication {
    private static final String URL = "jdbc:mysql://localhost:3306/javafx_db";
    private static final String USER = "malik"; // replace with your MySQL username
    private static final String PASSWORD = "5570"; // replace with your MySQL password

    public Connection getConnection() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }
}