#include "lambdas.hh"

strategy_type cooperator()
{
    return [](iterator_type, iterator_type) { return true; };
}

strategy_type cheater()
{
    return [](iterator_type, iterator_type) { return false; };
}

strategy_type copycat()
{
    return [](iterator_type begin, iterator_type end) {
        if (begin == end)
        {
            return true;
        }
        else
        {
            iterator_type last_move_it = end - 1;
            if (*last_move_it == 0 || *last_move_it == 3)
            {
                return false;
            }
            return true;
        }
    };
}

strategy_type grudger()
{
    return [](iterator_type begin, iterator_type end) {
        if (begin == end)
        {
            return true;
        }
        else
        {
            for (auto it = begin; begin != end; it++)
            {
                if (*it == 3 || *it == 0)
                    return false;
            }

            return true;
        }
    };
}

strategy_type detective()
{
    return [](iterator_type, iterator_type) { return true; };
}

strategy_type copykitten()
{
    return [](iterator_type begin, iterator_type end) {
        int nb_cheat = 0;
        for (auto it = begin; begin != end; it++)
        {
            if (*it == 3 || *it == 0)
                nb_cheat += 1;
        }

        if (begin == end)
        {
            return true;
        }
        else
        {
            iterator_type last_move_it = end - 1;
            if (*last_move_it == 0 || *last_move_it == 3)
            {
                if (nb_cheat >= 2)
                    return false;
            }
            return true;
        }
    };
}