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
    return (dice1_wins, dice2_wins)
#testing values
print('count_wins([1,2,3,4,5,6],[1,2,3,4,5,6]):',count_wins([1,2,3,4,5,6],[1,2,3,4,5,6]))
print('count_wins([1,1,6,6,8,8],[2,2,4,4,9,9]):',count_wins([1,1,6,6,8,8],[2,2,4,4,9,9]))
