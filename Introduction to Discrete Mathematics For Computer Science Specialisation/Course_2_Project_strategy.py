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

def compute_strategy(dices):
    assert all(len(dice) == 6 for dice in dices)
    strategy = dict()
    strategy["choose_first"] = True
    strategy["first_dice"] = 0
    #print(strategy) #to debug
    find_the_best_dice(dices)
    if find_the_best_dice(dices) != -1: #if there is a best dice
        strategy["first_dice"] = find_the_best_dice(dices) #set the value of first_dice to be the value of the index
        return strategy
    if find_the_best_dice(dices) == -1: #if there is no best dice
        strategy["choose_first"] = False
        del strategy["first_dice"] #delete first_dice key from strategy
        i = 0; j = 0 #loop through in a similar way and pass each dice into count_wins
        while i < len(dices)-1: #then pick the better dice between the 2 dice:
            j = i + 1
            while j < len(dices):
                count_wins(dices[i],dices[j]) #run count_wins again
                if count_wins(dices[i],dices[j]) == "{} > {}".format(dices[i],dices[j]):
                    strategy[j] = i
                if count_wins(dices[i],dices[j]) == "{} > {}".format(dices[j],dices[i]):
                    strategy[i] = j
                j = j + 1
            i = i+1
        return strategy
#Testing Values
print(compute_strategy([[1, 1, 4, 6, 7, 8], [2, 2, 2, 6, 7, 7], [3, 3, 3, 5, 5, 8]]))
#{choosefirst = False, 0:1, 1:2, 2:0}
print(compute_strategy([[4, 4, 4, 4, 0, 0], [7, 7, 3, 3, 3, 3], [6, 6, 2, 2, 2, 2], [5, 5, 5, 1, 1, 1]]))
#{"choosefirst = True, first_dice = 1"}
print(compute_strategy([[2, 2, 4, 5, 8, 9], [2, 3, 4, 5, 6, 10], [1, 2, 5, 6, 7, 8]]))
