from character import Character, Wizard, Knight, Rogue


def main():
    knight = Knight("Piotr", 100)
    wizard = Wizard("Maciek", 100)
    rogue = Rogue("Michal", 100)

    # TODO: get input from user and validate it
    number_of_tests: int = 10
    wizard_wins_vs_knight: int = 0
    wizard_wins_vs_rogue: int = 0
    knight_wins_vs_rogue: int = 0

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


def simulate_wizard_vs_knight(char1: Character, char2: Character):
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
    
    char1.roll_base()
    char2.roll_base()
    char1.passive_ability(char2.base_roll)
    char2.passive_ability()
    if sum(char1.base_roll) > sum(char2.base_roll):
        return True
    return False


def simulate_wizard_vs_rogue(char1: Character, char2: Character):
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

    char1.roll_base()
    char2.roll_base()
    char2.passive_ability(char1.base_roll)
    char1.passive_ability(char2.base_roll)
    if sum(char1.base_roll) > sum(char2.base_roll):
        return True
    return False


def simulate_knight_vs_rogue(char1: Character, char2: Character):
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

    char1.roll_base()
    char2.roll_base()
    char1.passive_ability()
    char2.passive_ability(char1.base_roll)
    if sum(char1.base_roll) > sum(char2.base_roll):
        return True
    return False


if __name__ == "__main__":
    main()
