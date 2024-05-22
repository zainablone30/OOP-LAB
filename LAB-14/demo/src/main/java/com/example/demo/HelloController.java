package com.example.demo;

import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class HelloController extends Application {
    private static final String URL = "jdbc:mysql://localhost:3306/javafx_db";
    private static final String USER = "malik"; // replace with your MySQL username
    private static final String PASSWORD = "5570"; // replace with your MySQL password

    @FXML
    private TextField usernameField;
    @FXML
    private PasswordField passwordField;

    public Connection getConnection() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }

    public void handleLogin() {
        String username = usernameField.getText();
        String password = passwordField.getText();

        try (Connection connection = getConnection()) {
            PreparedStatement statement = connection.prepareStatement("SELECT * FROM users WHERE username = ? AND password = ?");
            statement.setString(1, username);
            statement.setString(2, password);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
                System.out.println("Login successful");
            } else {
                System.out.println("login successful");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void switchToRegister() {
        try {
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("/src/main/resources/com/example/demo/register-view.fxml"));
            Scene scene = new Scene(fxmlLoader.load());
            Stage stage = (Stage) usernameField.getScene().getWindow();
            stage.setScene(scene);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("/com/example/demo/hello-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load());
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}