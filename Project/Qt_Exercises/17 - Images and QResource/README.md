# Instructions
## Display the Initial Image:
- In the ImageViewer constructor, use QPixmap to load the currentImage and set it on the QLabel with setPixmap().

## Implement Keyboard Shortcut:
- Override the keyPressEvent() method to detect when Ctrl+T is pressed.
- Toggle the value of currentImage between :/images/image1.png and :/images/image2.png.
- Update the QLabel with the new image.

## Test the Application:
- Verify that the initial image is displayed.
- Press Ctrl+T to switch between the two images.