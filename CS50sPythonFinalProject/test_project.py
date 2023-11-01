import project
import character


def main():
    test_simulate_wizard_vs_knight()
    test_simulate_wizard_vs_rogue()
    test_simulate_knight_vs_rogue()


def test_simulate_wizard_vs_knight():
    wizard = character.Wizard("Test Wizard", 100, "Wizard")
    knight = character.Knight("Test Knight", 100, "Knight")
    result = project.simulate_wizard_vs_knight(wizard, knight)
    assert result in [0, 1]


def test_simulate_wizard_vs_rogue():
    wizard = character.Wizard("Test Wizard", 100, "Wizard")
    rogue = character.Rogue("Test Rogue", 100, "Rogue")
    result = project.simulate_wizard_vs_rogue(wizard, rogue)
    assert result in [0, 1]


def test_simulate_knight_vs_rogue():
    knight = character.Knight("Test Knight", 100, "Knight")
    rogue = character.Rogue("Test Rogue", 100, "Rogue")
    result = project.simulate_knight_vs_rogue(knight, rogue)
    assert result in [0, 1]


if __name__ == "__main__":
    main()
