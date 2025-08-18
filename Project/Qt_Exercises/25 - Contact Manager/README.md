# Contact Management Application with JSON Storage

## Overview
In this exercise, you will create a simple **Contact Management Application** using Qt. The application will allow users to:
- Add, edit, and delete contacts
- Store the contact data in a **JSON file**
- Use a **file dialog** for opening and saving contacts

This exercise will help you practice with various Qt features like dialogs, file handling, and JSON manipulation. You will also learn how to build a responsive UI with lists, buttons, and input fields.

---

## Requirements

### 1. **Contact Model**
You will need a `Contact` class with the following attributes:
- `name` (QString)
- `email` (QString)
- `phone` (QString)

### 2. **Main Window**
The main window will include:
- A **QListWidget** to display the list of contacts.
- Buttons for:
  - **Add**: Opens a dialog to add a new contact.
  - **Edit**: Opens a dialog to edit the selected contact.
  - **Delete**: Deletes the selected contact.
  - **Save**: Saves the contacts to a JSON file.
  - **Load**: Loads contacts from a JSON file.

### 3. **JSON Storage**
The contacts will be saved and loaded from a **JSON file**. Each contact will be stored as a JSON object with the following fields:
- `name`
- `email`
- `phone`

You will need to serialize and deserialize the data to and from JSON format.

### 4. **Dialogs**
Use **QDialog** for the **Add/Edit** dialog that will allow users to input their contact information. The dialog will contain fields for `name`, `email`, and `phone`.

---

## Task List

### Step 1: Create the Contact Class
- Implement the `Contact` class with the necessary attributes and methods.
- Use appropriate getter and setter methods for `name`, `email`, and `phone`.

### Step 2: Build the Main Window UI
- Implement the main window with a `QListWidget` for displaying the contacts.
- Add buttons for the actions: Add, Edit, Delete, Save, and Load.

### Step 3: Implement Add/Edit Dialog
- Create a dialog (`QDialog`) with input fields (`QLineEdit`) for `name`, `email`, and `phone`.
- Implement the logic to accept the entered data when the OK button is clicked, and reject the dialog if any field is empty.
  
### Step 4: Implement the File Dialogs
- Use `QFileDialog` to open and save contacts from/to a **JSON file**.
- Implement the logic to serialize and deserialize contacts into JSON format using `QJsonDocument`, `QJsonObject`, and `QJsonArray`.

### Step 5: Save and Load Data
- Implement the logic to load contacts from the JSON file when the application starts.
- Implement the logic to save contacts back to the JSON file when the Save button is clicked.

### Step 6(Optional): Styling the Application
- Use **Qt Style Sheets** to style the UI components such as buttons, the contact list, and input fields.

---

## Notes

- **Dialog Validation**: Ensure that the user cannot add or edit a contact with empty fields. Show a warning if necessary.
- **JSON Structure**: The JSON file should contain an array of contact objects. Each object should have `name`, `email`, and `phone` fields.
  
Example of a JSON file:
```json
[
  {
    "name": "John Doe",
    "email": "johndoe@example.com",
    "phone": "123-456-7890"
  },
  {
    "name": "Jane Smith",
    "email": "janesmith@example.com",
    "phone": "987-654-3210"
  }
]
