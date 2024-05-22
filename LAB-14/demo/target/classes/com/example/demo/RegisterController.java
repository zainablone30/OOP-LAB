package com.example.demo;

import javafx.fxml.FXML;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;

public class RegisterController {
    @FXML
    private TextField usernameField;

    @FXML
    private PasswordField passwordField;

    public void handleRegister() {
        String username = usernameField.getText();
        String password = passwordField.getText();

        // Here you can add the code to handle the registration process
        // For example, you can add the user to your database
        System.out.println("Registering user with username: " + username + " and password: " + password);
    }

    public void switchToLogin() {
        // Here you can add the code to switch back to the login view
        System.out.println("Switching to login view");
    }
}