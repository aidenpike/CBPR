# CBPR
Remastered version of Country Battle Plus. Will likely get renamed.

# Versions
## Version 0.0
Complete! From here, I will list off bugs and updates, including things listed on the to do list below.

### To Do
- Setup check for weapon complexity level -3 to absolutely demolish you in battle
- Add color to text
- Add startup menu
- Find a way to put names in commander fights OR alternatively have player name their cmdr
- Balance the stats like a lot oh my god
- Make integer inputs non-integer capable
- Loop the current player's turn until they input an appropriate number

# Gameplay 
## Role of Chance
Dice play a primary role in the decision of the battles: upgrades add dice roles or lower the requirements for checks. 
## Turn Choices

### Expand Territory
10,000 for +1 Territory

### Upgrade Technology
Opens a list of options to upgrade, where each option has different effects.

#### Skill Training 
Train your armies’ battle skills to up the outcome of winning skirmishes.
- Adds to the battle roll for twice as much as its level (2d8 + (2 * Army Skill))
- Base price 8,000, increases by 800 * Army Skill

#### Endurance Training
In the works.
- Base price 8,000, increases by 1,000 * Army Endurance

#### Weapon Upgrade
Upgrade your weapon complexity. Be warned, however: the higher your complexity, the higher chance it has to fail in battle.
- Adds to the battle roll for 3 times as much as its level (2d8 + (3 * Weapon Complexity))
- Weapon Failure determined by 1d20 being less than 5 + 1 * Weapon Complexity - 50% of Army Skill
- Base Price 10,000, increases by 1000 * Weapon Complexity
  
#### Passive Income
By default, you gain 100 dollars every turn. However, this can be upgraded.
- +50 Passive Income per level
- Requires 1 territory per upgrade
- Base price 8,000, increases by 800 * Passive Income

#### Commander Upgrade
By default, the player starts out with a level 1 commander. They can be leveled up in the tech tree. Commanders boost the chance of winning skirmishes by adding their morale stat to the battle roll.
Commanders have a chance to fight opposing commanders (if both players have a commander) during skirmishes. This initiates a manual battle between the 2 commanders, and whoever wins will win the battle with their chosen outcome.
##### Commander Health
The health of the commander. Increases exponentially by 20% every level.
##### Commander Armor
The armor of the commander. This is hit first, and must be 0 before health can be damaged. Increases exponentially by 20% every level.
##### Commander Damage 
The damage of the commander. Increases exponentially by 10%.
##### Commander Morale
The morale boost from the commander. Increases exponentially by 5%. 
### Recruit Army
You recruit one army for 8,000 dollars.
    
## Battle
Player fights their opponent in a skirmish.
### Outcome Choice
A player can choose their goal for the outcome of the battle 
#### Devastate 
    Player can wreak havoc upon their opponent's territory.
        - Opponent loses 1 territory
        - Opponent loses 500-750 dollars
        - Opponent loses an army
    
#### Conquer
    Player conquers their opponent's territory.
        - Opponent loses 1 territory
        - Player gains 1 territory
        - Opponent loses 250-500 dollars
        - Player gains 250-500 dollars 

### Weapon Failure
    The complexity of a player's weapon both helps them in battle but also raises the risk.
    A player's weapons are capable of failing during battle, which can cause 1 of 3 outcomes: 
        - Player loses the battle and flees with one less army and a range of cash between 500-1000
        - Player manages to escape by a thread and only has to pay 500-1000 dollars
        - The battle was devastating. Player loses 1300-2000 dollars, 2 armies, and a weapon tech level 
## Pass
Passes your turn.

## List of Chances & Stats
### Stats
- Territory Count
- Army Count
- Technology Level
    - Army Skill
    - Army Endurance
    - Weapon Complexity (Weapon Upgrade Level)
    - Passive Income
    - Commander
        - Commander Damage
        - Commander Armor
        - Commander Health
        - Commander Morale
- Money 

### Chances [What Affects Them]
- Battle Chance
    - Devastation Chance [+Army Skill, +Army Endurance, +Weapon Complexity, -Weapon Failure]
        - Amount of money lost to devastation for opponent
    - Conquer Chance [+Army Skill, +Army Endurance, +Weapon Complexity, -Weapon Failure]
        - Amount of money lost to conquer for opponent
        - Amount of money gained from conquer for player
    - Battle Outcome
        - Chance for army to live or die [+Army Endurance]
        - Weapon Failure [-Weapon Complexity]
            - Battle outcome after weapon failure
                - Amount of money lost in outcome
- Chance for commanders to fight 

### Ideas
- choiceList() specific to what the player has
- Capital
    - Manage Capital Choice
    - Artillery 
    - Ability to storm territory with enemy capital
    - Grand Buildings - Dedicated buildings that have numerous boosts and multipliers to your stats (also they're very expensive)
        - Grand Science Building - Weapon failure chance reduced by half
        - Grand Barracks - .5 levels added per Army Skill, chance for 2 armies to be recruited
        - Grand Mine - .5 levels added per Passive Income, bonus 1000 passive income
- Make 2 pointer objects to lessen if/else statements
- Equipment for commander
- Commander accuracy: affects the chance that the commander hits
