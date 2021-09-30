punctuation_chars = ["'", '"', ",", ".", "!", ":", ";", '#', '@']
# lists of words to use
positive_words = []
with open("positive_words.txt") as pos_f:
    for lin in pos_f:
        if lin[0] != ';' and lin[0] != '\n':
            positive_words.append(lin.strip())


negative_words = []
with open("negative_words.txt") as pos_f:
    for lin in pos_f:
        if lin[0] != ';' and lin[0] != '\n':
            negative_words.append(lin.strip())
##User defined functions

def strip_punctuation(strings):
    for char in punctuation_chars:
        if char in strings:
                strings = strings.replace(char, '')
    return strings
##end func
def get_neg(sentence):
    string = strip_punctuation(sentence)
    string = string.lower()
    strlst = string.split()
    count = 0
    for char in negative_words:
        if char in strlst:
            count = count+1
    return count
##end func
def get_pos(sentence):
    string = strip_punctuation(sentence)
    string = string.lower()
    strlst = string.split()
    #print(strlst)
    count = 0;
    for char in positive_words:
        if char in strlst:
            count+=1
    return count
##end func
##Open project twitter data
fh = open("project_twitter_data.csv", "r")
ofp = open("resulting_data.csv", "w")
twitterlist = fh.readlines()
twitterlist = twitterlist[1:]
##Create a File header
ofp.write("Number of Retweets, Number of Replies, Positive Score, Negative Score, Net Score\n")
for line in twitterlist:
    line = line.strip("\n")
    line_lst = line.split(",")
    ##print(line_lst)
    sentence = strip_punctuation(line_lst[0]).lower()
    #print(sentence)
    ##Number of Retweets, Number of Replies, Positive Score, Negative Score
    ## and the Net Score
    pos = get_pos(sentence)
    neg = get_neg(sentence)
    ##Convert retweets from Char to int
    ret = int(line_lst[1])
    rep = int(line_lst[2])
    tup = (ret,rep, pos, neg, pos-neg)
    print(tup)
    ofp.write("{},{},{},{},{}\n".format(ret, rep, pos, neg, pos-neg))
fh.close()
ofp.close()
