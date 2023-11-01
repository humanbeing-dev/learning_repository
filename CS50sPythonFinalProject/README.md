# Game Balance Simulator

#### Video Demo:  [Watch the Demo](https://youtu.be/s0QH9nu-jMI)

#### Description:
**Game Balance Simulator** is a tool designed for a dice rolling game to refine and balance character mechanics in simulated battles. The simulator comprises two main files: **character.py** and **project.py**.

### character.py:
In this file, developer defines character attributes and passive abilities for various character classes. The **passive_ability()** function in each character class can be customized to modify the characters' strategic advantages. For instance:
- **Knight**: Adds one more d4 roll to its base roll, enhancing its defensive capabilities.
- **Rogue**: Adds two rolls if the opponent has more '6' rolls, showcasing its tactical prowess.
- **Wizard**: Rerolls one '1' roll; when facing the Rogue, counters with a d12 roll or rerolls one '2' roll for balance.

### project.py:
This file simulates battles between characters created in **character.py**. The **simulate_wizard_vs_knight(wizard, knight)** function orchestrates battles between Wizards and Knights, taking into account their respective abilities. Similarly, **simulate_wizard_vs_rogue(wizard, rogue)** and **simulate_knight_vs_rogue(knight, rogue)** simulate confrontations between Wizards and Rogues, and Knights and Rogues, respectively.

### How to Use:
1. Adjust the **passive_ability()** function in **character.py** for each character class to modify their abilities.
2. Run **project.py** to simulate battles based on the updated abilities.
3. Analyze the win ratios for each encounter to understand the impact of the modifications made.

### Current Game Balance:
The default game mechanics have been balanced to favor the Knight in skirmishes with the Wizard, the Wizard in skirmishes with the Rogue, and the Rogue in skirmishes with the Knight. Developers can use this balanced foundation as a starting point and further customize character abilities to suit their game's unique requirements.

Explore the **Game Balance Simulator** and create strategically balanced gaming experiences for your players!
