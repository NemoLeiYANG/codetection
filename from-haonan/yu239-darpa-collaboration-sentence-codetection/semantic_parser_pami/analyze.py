#!/usr/bin/python

import nltk
from nltk.stem.wordnet import WordNetLemmatizer as wnl
from itertools import groupby
import json
import re
import cPickle as pickle
import sys

id = ""

def assoc(key, pairs):
    for p in pairs:
        if p[0] == key:
            return p
    return False

def dump_list(lst, f):
    for l in lst:
        print >> f, l

def words2sentence(words):
    return " ".join([w[0] for w in words])

## compute some statistics
## 1. all distinct POS, each with a list of words
## 2. all distinct words, each with a list of POS
def statistics(sentences):
    tags = [tag for s in sentences for tag in s]
    k = lambda x: x[1]
    pos = groupby(sorted(tags, key=k), k)
    k = lambda x: x[0]
    lexicon = groupby(sorted(tags, key=k), k)
    pos_dict = {}
    for p, g in pos:
        pos_dict[p] = list(set([tag[0] for tag in list(g)]))
    lexicon_dict = {}
    for w, g in lexicon:
        lexicon_dict[w] = list(set([tag[1] for tag in list(g)]))
    return (pos_dict, lexicon_dict)

################# Step 1 ####################
## parse every sentence to get words taged with POS
def all_pos(sentences):
    sentences = [nltk.pos_tag(nltk.word_tokenize(s.strip().lower())) \
                 for s in sentences]
    pickle.dump(sentences, open("%s/sentences.tagged.1"%id, "wb"), protocol=pickle.HIGHEST_PROTOCOL)

    pos_dict, lexicon_dict = statistics(sentences)
    # each variable on a new line (indent = 2)
    json.dump(pos_dict, open("%s/pos.dict.1"%id, "w"), indent=2)  
    # json.dump(lexicon_dict, open("%s/lexicon.dict.1"%id, "w"), indent=2)

################# Step 2 ###################
## the parsing might make errors on the tagging
## so we manually correct the tagging according to our correction list
## and lemmatize the words
## and remove some irrelevant pos
def clean_pos():
    def lemmatize(tags):
        for i,t in enumerate(tags):
            # noun
            if t[1].startswith("NN"):
                tags[i] = (wnl().lemmatize(t[0],'n'), "NN")
            # verb
            if t[1].startswith("VB"):
                tags[i] = (wnl().lemmatize(t[0],'v'), "VB")
        return tags

    sentences = pickle.load(open("%s/sentences.tagged.1"%id,"rb"))
    with open("%s/pos.corr"%id,"r") as f:
        correction = eval("".join(f.readlines()))
    with open("%s/pos.clean"%id,"r") as f:
        to_remove = eval("".join(f.readlines()))

    # update
    for s in sentences:
        for i,t in enumerate(s):
            found = assoc(t[0], correction)
            if found:
                s[i] = found
    # remove some pos
    sentences = [[t for t in lemmatize(s) if not t[1] in to_remove] \
                 for s in sentences]

    pickle.dump(sentences, open("%s/sentences.tagged.2"%id, "wb"), protocol=pickle.HIGHEST_PROTOCOL)
    dump_list([words2sentence(s) for s in sentences], open("%s/sentences.txt.2"%id, "w"))

    pos_dict, lexicon_dict = statistics(sentences)
    json.dump(pos_dict, open("%s/pos.dict.2"%id, "w"), indent=2)  
    # json.dump(lexicon_dict, open("%s/lexicon.dict.2"%id, "w"), indent=2)    

def map_phrases():
    with open("%s/sentences.txt.2"%id, "r") as f:
        sentences = [s.strip() for s in f.readlines()]
    with open("%s/phrases.map"%id, "r") as f:
        mapping = eval("".join(f.readlines()))
    # sort the mapping so that longer phrases are always first
    mapping = sorted(mapping, key=lambda m: -len(m[0].split(" ")))

    while True:
        changed = False
        for i in range(len(sentences)):
            s = " " + sentences[i] + " "
            for m in mapping:
                if (" "+m[0]+" ") in s:
                    sentences[i] = re.sub(" +", " ", s.replace(" "+m[0]+" ", " "+m[1]+" ")).strip()
                    s = " " + sentences[i] + " "
                    changed = True
        if not changed:
            break

    dump_list(sentences, open("%s/sentences.txt.dry"%id, "w"))
    dump_list(list(set([w for s in sentences for w in s.split(" ")])), \
              open("%s/voc.txt"%id, "w"))

if __name__ == "__main__":
    if len(sys.argv) < 1:
        print "usage: ./analyze.py <dataset-id>"
        sys.exit()
    id = sys.argv[1]        
    with open("%s/sentences.results.ispelled" % id, "r") as f:
        vs_pairs = f.readlines()
        vs_pairs = [p.split("|") for p in vs_pairs]
        videos, sentences = zip(*vs_pairs)
        dump_list(videos, open("%s/videos.txt"%id, "w"))

#    all_pos(sentences)
#    clean_pos()
    map_phrases()
