#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>

#define SUPERAUTH_UID 0
#define SUPERAUTH_USERNAME "superconf"

// Structure to hold user information
typedef struct {
    int uid;  // User ID (UID)
    char username[50];  // Username
} User;

// Define the superconf user (root equivalent)
User superconf_user = {SUPERAUTH_UID, SUPERAUTH_USERNAME};

// Function to check if the system is ARM64 architecture
int is_arm64() {
    struct utsname uname_info;
    if (uname(&uname_info) != 0) {
        perror("uname");
        return 0;  // If uname fails, assume it's not ARM64
    }

    // Check if the architecture is "aarch64", which is ARM64
    if (strcmp(uname_info.machine, "aarch64") == 0) {
        return 1;  // It's ARM64
    }
    return 0;  // Not ARM64
}

// Authentication function
int authenticate(User *user) {
    char input_username[50];
    char input_password[50];

    printf("Username: ");
    scanf("%s", input_username);

    printf("Password: ");
    scanf("%s", input_password); // Password validation can be added

    // Check username
    if (strcmp(user->username, input_username) == 0) {
        printf("Login successful! Welcome, superconf user.\n");
        return 1;
    } else {
        printf("Invalid username.\n");
        return 0;
    }
}

// Perform superconf (root) actions
void perform_superconf_action() {
    printf("Performing superconf (root) actions...\n");
    printf("System administration task completed.\n");
}

// Perform normal user actions
void perform_normal_user_action() {
    printf("Performing normal user actions...\n");
}

int main() {
    // Check if the system is ARM64
    if (!is_arm64()) {
        printf("This program can only run on ARM64 architecture.\n");
        return 1;  // Exit if not ARM64
    }

    User current_user;

    // User authentication
    if (authenticate(&current_user)) {
        if (current_user.uid == SUPERAUTH_UID) {
            // Superconf (root) actions
            perform_superconf_action();
        } else {
            // Normal user actions
            perform_normal_user_action();
        }
    } else {
        printf("Login failed.\n");
    }

    return 0;
}
