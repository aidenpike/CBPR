# CBPR
Remastered version of Country Battle Plus. 

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

- +1d8 to Devastate Check
- +1d8 to Conquer Check
- +1d8 to Pillage Check

#### Endurance Training
- +1d8 to chance for army survival during battles

#### Weapon Upgrade
- +1d10 to Devastate Check
- +1d10 to Conquer Check
- +1d8 to Pillage Check
  
#### Passive Income
By default, you gain 100 dollars every turn. However, this can be upgraded.
- +50 Passive Income
- Requires 1 territory per upgrade

#### Commander Upgrade
By default, the player starts out with no commander. They can hire one through this tree, and upgrade their stats individually. Commanders boost the chance of winning skirmishes, and slightly boost morale of the soldiers, increasing the soldier skill stat chance by half of its level.
Commanders have a chance to fight opposing commanders (if both players have a commander) during skirmishes. This initiates a manual battle between the 2 commanders, and whoever wins will win the battle with their chosen outcome.
##### Commander Health
The health of the commander. 
##### Commander Armor
The armor of the commander. 
##### Commander Damage 
The damage of the commander.
### Recruit Army
8000 for +1 Army
    
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
        - Player manages to win by a thread and only have to pay 500-1000 dollars
        - The battle was devastating. Player loses 1300-2000 dollars, 2 armies, and a weapon tech level 
## Pass

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
- Money

### Chances [What Affects Them]
- Battle Chance
    - Devastation Chance [+Army Skill, +Army Endurance, +Weapon Complexity, -Weapon Failure]
        - Amount of money lost to devastation for opponent
    - Conquer Chance [+Army Skill, +Army Endurance, +Weapon Complexity, -Weapon Failure]
        - Amount of money lost to conquer for opponent
        - Amount of money gained from conquer for player
    - Army Endurance
    - Weapon Failure [-Weapon Complexity]
        - Battle outcome after weapon failure
            - Amount of money lost in outcome
# Versions
## Version 0.0
In the works!

### To Do
- passiveIncome()
- Tech upgrade price scaling 
- weaponFailure()
- Commander Class
    - Likely one function for level up that ups the stats each level
    - cmdrBattle()
    - Commander Stats
        - p[One or Two]CmdrLevel
        - p[One or Two]CmdrATK
        - p[One or Two]CmdrDEF
        - p[One or Two]CmdrMOR

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
