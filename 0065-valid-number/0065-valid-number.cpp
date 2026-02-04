class Solution {
    enum State {
        EXPONENT,
        DECIMAL,
        INTEGER,
        START,
        EMPTY_INTEGER,
        EMPTY_DECIMAL,
        EXPONENT_START,
        EMPTY_EXPONENT,
        FAIL,
    };
    enum Token {
        SIGN,
        DIGIT,
        DOT,
        EXP,
        OTHER,
    };
    State transition[FAIL][OTHER] = {
        /* EXPONENT */       {FAIL, EXPONENT, FAIL, FAIL},
        /* DECIMAL */        {FAIL, DECIMAL, FAIL, EXPONENT_START},
        /* INTEGER */        {FAIL, INTEGER, DECIMAL, EXPONENT_START},
        /* START */          {EMPTY_INTEGER, INTEGER, EMPTY_DECIMAL, FAIL},
        /* EMPTY_INTEGER */  {FAIL, INTEGER, EMPTY_DECIMAL, FAIL},
        /* EMPTY_DECIMAL */  {FAIL, DECIMAL, FAIL, FAIL},
        /* EXPONENT_START */ {EMPTY_EXPONENT, EXPONENT, FAIL, FAIL},
        /* EMPTY_EXPONENT */ {FAIL, EXPONENT, FAIL, FAIL},
    };
    Token parse(char c) {
        switch (c) {
            case '+':
            case '-': return SIGN;
            case '.': return DOT;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': return DIGIT;
            case 'e':
            case 'E': return EXP;
            default: return OTHER;
        }
    }
public:
    bool isNumber(string s) {
        State state = START;
        for (const char c : s) {
            const Token ch = parse(c);
            if (ch == OTHER) { return false; }
            state = transition[state][ch];
            if (state == FAIL) { return false; }
        }
        return state < START;
    }
};