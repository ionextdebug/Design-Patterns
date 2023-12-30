package javap.factories;

import javap.buttons.Button;
import javap.buttons.WindowsButton;
import javap.checkboxes.Checkbox;
import javap.checkboxes.WindowsCheckbox;

public class WindowsFactory implements GUIFactory {
    @Override
    public Button createButton(){
        return new WindowsButton();
    }

    @Override
    public Checkbox createCheckbox(){
        return new WindowsCheckbox();
    }
}
