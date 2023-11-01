from character import Wizard, Knight, Rogue


def main():
    knight = Knight("Piotr", 100)
    wizard = Wizard("Maciek", 100)
    rogue = Rogue("Michal", 100)

    number_of_tests = 100000
    wizard_wins_vs_knight = 0
    wizard_wins_vs_rogue = 0
    knight_wins_vs_rogue = 0

    for _ in range(number_of_tests):
        # simulate fight wizard vs knight
        wizard_wins_vs_knight += simulate_wizard_vs_knight(wizard, knight)
        # simulate fight wizzard vs rogue
        wizard_wins_vs_rogue += simulate_wizard_vs_rogue(wizard, rogue)
        # simulate fight knight vs rogue
        knight_wins_vs_rogue += simulate_knight_vs_rogue(knight, rogue)

    print(
        f"Wizard win % vs knight is: {wizard_wins_vs_knight / number_of_tests * 100:.2f}%"
    )
    print(
        f"Wizard win % vs rogue is: {wizard_wins_vs_rogue / number_of_tests * 100:.2f}%"
    )
    print(
        f"Knight win % vs rogue is: {knight_wins_vs_rogue / number_of_tests * 100:.2f}%"
    )


def simulate_wizard_vs_knight(wizard, knight):
    """
    Wizard's passive ability when fighting knight is used before knight applies its passive.
    Returns 1 if Wizard has won with a Knight and 0 if Wizard has lost.
    - Modify this mechanic to balance out the game
    - This has been balanced in favor for Knight when playing against Wizard

    :param wizard: Wizard Character class
    :type wizard: character.Wizard
    :param knight: Knight Character class
    :type knight: character.Knight
    :return: integer
    :rtype: int
    """
    wizard.roll_base()
    knight.roll_base()
    wizard.passive_ability(knight.base_roll)
    knight.passive_ability()
    if sum(wizard.base_roll) > sum(knight.base_roll):
        return 1
    else:
        return 0


def simulate_wizard_vs_rogue(wizard, rogue):
    """
    Wizard's passive ability when fighting knight is used after Rogue applies its passive.
    Returns 1 if Wizard has won with a Rogue and 0 if Wizard has lost.
    - Modify this mechanic to balance out the game
    - This has been balanced in favor for Knight when playing against Wizard

    :param wizard: Wizard Character class
    :type wizard: character.Wizard
    :param rogue: Rogue Character class
    :type rogue: character.Rogue
    :return: integer
    :rtype: int
    """
    wizard.roll_base()
    rogue.roll_base()
    rogue.passive_ability(wizard.base_roll)
    wizard.passive_ability(rogue.base_roll)
    if sum(wizard.base_roll) > sum(rogue.base_roll):
        return 1
    else:
        return 0


def simulate_knight_vs_rogue(knight, rogue):
    """
    Knight's passive ability when fighting Rogue is used before Rogue applies its passive.
    Returns 1 if knight has won with a Rogue and 0 if Knight has lost.
    - Modify this mechanic to balance out the game
    - This has been balanced in favor for Rogue when playing against Knight

    :param knight: Knight Character class
    :type knight: character.Knight
    :param rogue: Rogue Character class
    :type rogue: character.Rogue
    :return: integer
    :rtype: int
    """
    knight.roll_base()
    rogue.roll_base()
    knight.passive_ability()
    rogue.passive_ability(knight.base_roll)
    if sum(knight.base_roll) > sum(rogue.base_roll):
        return 1
    else:
        return 0


if __name__ == "__main__":
    main()
