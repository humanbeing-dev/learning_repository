import character


def main():
    test_roll_base()
    test_wizard_ability_with_8_elements()
    test_knight_ability()
    test_rogue_ability()


def test_roll_base():
    character_instance = character.Character("Test Character", 100)
    character_instance.roll_base()
    assert len(character_instance.base_roll) == 6
    assert all(1 <= x <= 6 for x in character_instance.base_roll)


def test_wizard_ability_with_8_elements():
    wizard = character.Wizard("TestWizard", 100, "Wizard")
    wizard.base_roll = [3, 4, 5, 6, 1, 2]  # Base roll with 6 elements
    wizard.ability([1, 2, 3, 4, 5, 6, 1, 2])  # other_base_roll with 8 elements
    assert 12 in wizard.base_roll


def test_knight_ability():
    knight = character.Knight("TestKnight", 100, "Wizard")
    knight.base_roll = [1, 2, 3, 4, 5, 6]
    knight.ability()
    assert len(knight.base_roll) == 7


def test_rogue_ability():
    rogue = character.Rogue("TestRogue", 100, "Wizard")
    rogue.base_roll = [1, 2, 3, 4, 5, 6]
    rogue.ability([1, 2, 3, 4, 6, 6])
    assert len(rogue.base_roll) == 8


if __name__ == "__main__":
    main()
