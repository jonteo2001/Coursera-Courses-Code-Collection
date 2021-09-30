def count_wins(dice1, dice2):
    assert len(dice1) == 6 and len(dice2) == 6
    dice1_wins, dice2_wins = 0, 0

    #write code here

    dice1result = 0; dice2result = 0
    i = 0; j = 0
    while i < len(dice1):
        dice1result = dice1[i]
        j = 0
        while j < len(dice2):
            dice2result = dice2[j]
            if dice1result >  dice2result: dice1_wins +=1;
            elif dice1result < dice2result: dice2_wins +=1;
            j = j+1
        i = i + 1
    if dice1_wins > dice2_wins:
        return "{} > {}".format(dice1,dice2)
    elif dice1_wins < dice2_wins:
        return "{} > {}".format(dice2,dice1)
    else: return "{} = {}".format(dice1,dice2)

def find_the_best_dice(dices):
    wins_dice = dict()
    assert all(len(dice) == 6 for dice in dices)
    i = 0; j = 0
    while i < len(dices)-1:
        j = i + 1
        while j < len(dices):
            count_wins(dices[i],dices[j])
            if count_wins(dices[i],dices[j]) == "{} > {}".format(dices[i],dices[j]):
                wins_dice[i] = wins_dice.get(i,0) + 1
                wins_dice[j] = wins_dice.get(j,0)
            if count_wins(dices[i],dices[j]) == "{} > {}".format(dices[j],dices[i]):
                wins_dice[j] = wins_dice.get(j,0) + 1
                wins_dice[i] = wins_dice.get(i,0)
            j = j+1
        i = i+1;
    #print(wins_dice)
    all_values = wins_dice.values()
    max_value = max(all_values)
    if max_value == len(dices) - 2: return -1
    else: return max(wins_dice, key=wins_dice.get)

#Testing values
print(find_the_best_dice([[1, 1, 6, 6, 8, 8], [2, 2, 4, 4, 9, 9], [3, 3, 5, 5, 7, 7]]))
print(find_the_best_dice([[1, 1, 2, 4, 5, 7], [1, 2, 2, 3, 4, 7], [1, 2, 3, 4, 5, 6]]))
print(find_the_best_dice([[3, 3, 3, 3, 3, 3], [6, 6, 2, 2, 2, 2], [4, 4, 4, 4, 0, 0], [5, 5, 5, 1, 1, 1]]))
