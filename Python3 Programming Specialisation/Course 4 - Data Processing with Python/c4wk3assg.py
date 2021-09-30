#Some functions
VOWEL_COST = 250
LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
VOWELS = 'AEIOU'
# Returns a string representing the current state of the game
def showBoard(category, obscuredPhrase, guessed):
    return """
Category: {}
Phrase:   {}
Guessed:  {}\n\n""".format(category, obscuredPhrase, ', '.join(sorted(guessed)))
# Write the WOFPlayer class definition (part A) here
class WOFPlayer:
    def __init__(self,name):
        self.name = name
        self.prizeMoney = 0
        self.prizes = []
    def addMoney(self, amt):
        self.prizeMoney+=amt
    def goBankrupt(self):
        self.prizeMoney = 0
    def addPrize(self, prize):
        self.prizes.append(prize)
    def __str__(self):
        return "{} (${})".format(self.name, self.prizeMoney)
class WOFHumanPlayer(WOFPlayer):
    def getMove(self, category, obscuredPhrase, guessed):
        msg1 = "{} has ${}.\n\n".format(self.name, self.prizeMoney)
        msg2 = showBoard(category, obscuredPhrase, guessed)
        print(msg1+msg2)
        string = str(input("Guess a letter, phrase, or type 'exit' or 'pass':"))
        return string
class WOFComputerPlayer(WOFPlayer):
    SORTED_FREQUENCIES = 'ZQXJKVBPYGFWMUCLDRHSNIOATE'
    def __init__(self,name,diff):
        self.name = name
        self.difficulty = diff
        self.prizeMoney = 0
        self.prizes = []
    def smartCoinFlip(self):
        num = random.randint(1,10)
        if (num > self.difficulty):
            return True
        else:
            return False
    def getPossibleLetters(self, guessed):
        letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        possible = list()
        for char in letters:
            if char not in guessed:
                if char in VOWELS:
                    if (self.prizeMoney >=250):
                        possible.append(char)
                    else:
                        pass
                else: # char not a vowel.
                    possible.append(char)
            else:# if char in guessed
                pass
        return possible
    def getMove(self, category, obscuredPhrase, guessed):
        msg1 = "{} has ${}.\n\n".format(self.name, self.prizeMoney)
        msg2 = showBoard(category, obscuredPhrase, guessed)
        print(msg1+msg2)
        possible = self.getPossibleLetters(guessed)
        if (len(possible) == 0):
            return 'pass'
        if (self.smartCoinFlip() == False):
            return random.choice(possible)
        else:
            for i in range(0,len(self.SORTED_FREQUENCIES)):
                if self.SORTED_FREQUENCIES[::-1][i] in possible:
                    return self.SORTED_FREQUENCIES[::-1][i]
