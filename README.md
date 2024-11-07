# CBPR
Built off of [Country Battle](https://github.com/aidenpike/schoolprojects/tree/main/Country%20Battle) and then [Country Battle+](https://github.com/aidenpike/country-battle-plus), [Country Battle Plus Remastered](https://github.com/aidenpike/CBPR) is a text-based mimic 4X game between 2 players where the goal is to exhaust the other player in some way (e.g. money, territories, etc).

## Why so Many Extensions?
I usually add an extension to the prior name when I rewrite or reformat the code entirely.

# Versions
Numbers before the decimal are major (e.g. 1.0).
Numbers after the decimal are minor or bug fixes (e.g. 0.1)
## Version 0.0
Complete! From here, I will list off bugs and updates, including things listed on the to do list below.
## Version 0.1
Complete!
- Added money tags
- Added comma seperation for nums above 999
- Added disallowing player to buy upgrades beyond base price
- Fixed commander stats remaining the same as previous battle
- Fixed weapon complexity saying not enough money when there's enough money
- Added SOME color to text (may be more later, also note that this color currently only works in ANSI)
- Added current prices next to each technology in the tree
- Fixed integer inputs not being able to take non-integer inputs
- Added looping the player's turn until they input an appropriate number

### To Do
- Setup check for weapon complexity level -3 to absolutely demolish you in battle
- Add more color to text
- Add startup menu
- Find a way to put names in commander fights OR alternatively have player name their cmdr
- Balance the stats like a lot oh my god
- Equipment for commander
#### Bugs

# Ideas
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
 - Commander accuracy: affects the chance that the commander hits
 - Different soldier unit types
     - Pikeman
     - Horseman
     - Swordsman
 - Commander skillset
