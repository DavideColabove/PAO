# Instructions
## Complete CounterButtonInheritance (Inheritance Approach):
- Set the initial text of the button in its constructor.
- Connect the clicked signal to the incrementCounter slot.
- Implement the incrementCounter method to increment the counter and update the button's text.

## Complete CounterWidgetComposition (Composition Approach):
- Initialize the button and label in the constructor.
- Add them to a QVBoxLayout.
- Connect the clicked signal of the button to the incrementCounter slot.
- Implement the incrementCounter method to update the label text.

## Update main.cpp:
- Create instances of both widgets and add them as tabs in the QTabWidget.

## Analyze the Results:
- Compare the inheritance-based implementation with the composition-based implementation.
- Identify scenarios where one approach might be more suitable than the other.