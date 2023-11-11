from abc import ABC, abstractmethod
import random
from typing import List


def roll_dice(x: int) -> int:
    """
    Roll dice with x number of sides.

    :param x: Number of sides
    :type x: int
    :raise ValueError: If x is not an int
    :return: A number in range of 1 to x.
    :rtype: int
    """
    if isinstance(x, int) and x > 0:
        return random.randint(1, x)
    else:
        raise ValueError("Invalid number for a dice roll")


class Character(ABC):
    def __init__(self, name: str, health: int):
        self.name = name
        self.health = health
        self.base_roll: List[int] = []

    @abstractmethod
    def passive_ability(self, other_base_roll):
        pass

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, name):
        if isinstance(name, str) and len(name) > 0:
            self._name = name
        else:
            raise ValueError("Invalid name. Name must be a non-empty string")

    @property
    def health(self):
        return self._health

    @health.setter
    def health(self, health):
        if isinstance(health, int) and health > 0:
            self._health = health
        else:
            raise ValueError(
                "Invalid health number. Health has to be an int bigger then 0"
            )

    def roll_base(self) -> None:
        self.base_roll = [roll_dice(6) for _ in range(6)]


class Knight(Character):
    def __init__(self, name, hp):
        # Call the constructor of the parent class to initialize name and hp attributes
        super().__init__(name, hp)
        self._profession = "Knight"

    def passive_ability(self):
        """
        Knights' passive ability adds one more d4 roll to its base roll.
        - Modify this mechanic to balance out the game
        - This has been balanced in favor for Knight when fighting against the Wizard

        :return: List of integers
        :rtype: List[int]
        """
        self.base_roll.append(roll_dice(4))
        return self.base_roll


class Rogue(Character):
    def __init__(self, name, hp):
        # Call the constructor of the parent class to initialize name and hp attributes
        super().__init__(name, hp)
        self._profession = "Rogue"

    def passive_ability(self, other_base_roll):
        """
        Rogue passive ability allows adding 2 rolls if the opponent has more '6' rolls in its base roll list.
        - Modify this mechanic to balance out the game
        - This has been balanced in favor for Rogue, when playing against the Knight

        :param other_base_roll: Opponent's base roll.
        :type other_base_roll: List[int]
        :return: List of integers
        :rtype: List[int]
        """
        if (
            other_base_roll.count(6) > self.base_roll.count(6)
            or sum(self.base_roll) < 18
        ):
            self.base_roll.append(roll_dice(6))
            self.base_roll.append(roll_dice(6))


class Wizard(Character):
    def __init__(self, name, hp):
        # Call the constructor of the parent class to initialize name and hp attributes
        super().__init__(name, hp)
        self._profession = "Wizard"

    def passive_ability(self, other_base_roll: List[int]):
        """
        Wizards' passive ability allows for reroll of one '1' roll.
        Along with that, when Wizard plays against the Rogue, which has its passive activated,
        he is able to counter with rerolling one '1' roll with d12 roll.
        If '1' is not available, Wizard rerolls one '2' roll.
        - Modify this mechanic to balance out the game
        - This has been balanced in favor for Wizard when playing against the Rogue

        :param other_base_roll: Opponent's base roll.
        :type other_base_roll: List[int]
        :return: List of integers
        :rtype: List[int]
        """
        if 1 in self.base_roll:
            self.base_roll.remove(1)
            self.base_roll.append(roll_dice(6))
        if len(other_base_roll) == 8 and 1 in self.base_roll:
            self.base_roll.remove(1)
            self.base_roll.append(12)
        elif len(other_base_roll) == 8 and 2 in self.base_roll:
            self.base_roll.remove(2)
            self.base_roll.append(12)
        return self.base_roll
