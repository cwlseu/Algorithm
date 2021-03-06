# 算法之道
## 熟能生巧。
想想高中之前学习的东西，每个东西对应着几十几百次练习，所以渐渐地学会了。然而，高中之后的学习过程就不再是
重复模式，而是快餐模式。所学的东西，都是眨眼而过，要真正领会，需要花功夫去揣摩。算法也是如此。可能一遍我
没有弄明白，那么几次下去，应该会有印象了。但是，明白了其道理，还不一定能够真正灵活运用到实际项目中，而要
达到灵活运用，还是要多多*重构*，在重构中发现是否可以使用设计模式，是否可以使用新的算法进行性能提升....

## 源于生活
每个算法都是来源于生活实际。没有实际应用的算法是无用的。要么是为了提高效率，要么是为了解决实际问题。而实际
问题与算法之间还需要经过建模抽象的过程，这个过程就要看个人了。

## 算法的好坏是相对的
好的算法也许看上去很简单，而复杂的算法也许运行的很快，算法的好坏只有实验数据才能说话。大数据环境下，

    简单的算法 + 大量的数据 > 复杂的算法

不管是从现在新闻，还是技术博客，出现最多的就是*大数据*，那么什么是大数据？数据量大只是一个特点罢了，只要
稍微接触过数据挖掘的技术人员来说，都知道大数据的4V特点，但是有没有注意到，在大数据环境下，我们的处理数据
的算法是继续向着复杂方向发展吗？其实不然，算法复杂性不仅没有增加，反而10年前的一些算法收到青睐，一个是代码
实现简单，方便并行化，另一个就是这些算法经过多年的锤炼，更加准确，方便，各种库都包含了。现在大数据程序员，
需要有好的代码规范之外，就是要好好调API了。当然，高级程序员要另外说，cache优化，各种tradeoff横飞还是存在
的，这些需要我们的大牛们继续努力。

## 多敲胜于多想，多用胜于多读
毕竟算法要用于实践，我们的算法再怎么棒，不能实现也是空谈罢了。算法是个实战主义者。

# C++ Practise
C++ is a great program language. But it's difficult for
me to learn deeply. So more practise should be do.

```
.
├── cppbasic
│   ├── add_without_arithmetic.cpp
│   ├── alignPtr.cpp
│   ├── datatype.cpp
│   ├── func_neq_func.cpp
│   ├── gcd.cpp
│   ├── leftshiftchar.cpp
│   ├── memcpy.cpp
│   ├── no_if.cpp
│   ├── perm.cpp
│   ├── p_func_test.cpp
│   ├── powerlogn.cpp
│   ├── README.md
│   ├── return_arr_pointer.cpp
│   ├── revert_int32.cpp
│   ├── template.cpp
│   ├── template_gen.cpp
│   ├── template_input.cpp
│   ├── transform_demo.cpp
│   ├── unexceptedexception.cpp
│   ├── virtualTable.cpp
│   └── VirtualTest.cpp
├── dp
│   ├── matrix_multiply
│   ├── max_num_pair_diff
│   └── wordbreak
├── lists
│   ├── existcircle.c
│   └── reverseList.cpp
├── python
│   ├── 1-add2sum.py
│   ├── 46-Permutations.py
│   ├── cache_result_decorator.py
│   ├── calc_PI.py
│   ├── Divide-And-Conquer.py
│   ├── find_target_sum.py
│   ├── longestIncreasing.py
│   ├── minPatches.py
│   ├── SymmetrixTree.py
│   └── utility
├── shell
│   ├── before_boost_install.sh
│   ├── before_use_ubuntu.sh
│   ├── caffe_dependence_package.txt
│   ├── caffe_install.sh
│   ├── install_fuchsia_kernal_magenta.sh
│   ├── INSTALL_MAGENTA.sh
│   ├── install_software.list
│   ├── install_software.txt
│   ├── install_theano.sh
│   ├── install_wine
│   ├── magenta.txt
│   ├── requistionlist.txt
│   ├── setup.sh
│   └── Shell programming.pdf
├── sort_and_search
│   ├── bubblesort.c
│   ├── bubblesort_testcase.txt
│   ├── min_k_num.cpp
│   ├── nth_element.cpp
│   ├── odd_even_sort.cpp
│   └── randomselect.cpp
├── stl_source
│   └── stl_test
└── string
    ├── reverse_word.cpp
    └── stack_reverse_word.cpp
```