
#define FLAG_LIST(_)                   \
    _(InWorklist)                      \
    _(EmittedAtUses)                   \
    _(LoopInvariant)                   \
    _(Commutative)                     \
    _(Movable)                         \
    _(Lowered)                         \
    _(Guard)

#define DEFINE_FLAG(flag) flag,
enum Flag {
    None = 0,
    FLAG_LIST(DEFINE_FLAG)
    Total
};
#undef DEFINE_FLAG
int main()
{
    return 0;
}
