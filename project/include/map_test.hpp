#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

#include <map.hpp>
#include <iomanip>

template <typename T>
void print_int_key_node_fluid(ft::Node<ft::pair<const int, T> > *node) ;
template <typename T>
void tree_picture_fluid(ft::map<int, T> &my_tree) ;

template <typename T>
    void    fill_map_insert_loop(ft::map<int, T> &map_int);

template <typename T>
    void    fill_map_insert_loop(ft::map<int, T> &map_int) {

                                                                // int i = 0;  std::cout << " i = " << i++ << std::endl;
map_int.insert( ft::make_pair( 846930886, 846930886) );         // std::cout << " i = " << i++ << std::endl; // i = 0
map_int.insert( ft::make_pair( 1714636915, 1714636915) );       // std::cout << " i = " << i++ << std::endl; // i = 1
map_int.insert( ft::make_pair( 424238335, 424238335) );         // std::cout << " i = " << i++ << std::endl; // i = 2
map_int.insert( ft::make_pair( 1649760492, 1649760492) );       // std::cout << " i = " << i++ << std::endl; // i = 3
map_int.insert( ft::make_pair( 1189641421, 1189641421) );       // std::cout << " i = " << i++ << std::endl; // i = 4
map_int.insert( ft::make_pair( 1350490027, 1350490027) );       // std::cout << " i = " << i++ << std::endl; // i = 5
map_int.insert( ft::make_pair( 1102520059, 1102520059) );       // std::cout << " i = " << i++ << std::endl; // i = 6
map_int.insert( ft::make_pair( 1967513926, 1967513926) );       // std::cout << " i = " << i++ << std::endl; // i = 7
map_int.insert( ft::make_pair( 1540383426, 1540383426) );       // std::cout << " i = " << i++ << std::endl; // i = 8
map_int.insert( ft::make_pair( 1303455736, 1303455736) );       // std::cout << " i = " << i++ << std::endl; // i = 9
map_int.insert( ft::make_pair( 521595368, 521595368) );         // std::cout << " i = " << i++ << std::endl; // i = 10
map_int.insert( ft::make_pair( 1726956429, 1726956429) );       // std::cout << " i = " << i++ << std::endl; // i = 11
map_int.insert( ft::make_pair( 861021530, 861021530) );         // std::cout << " i = " << i++ << std::endl; // i = 12
map_int.insert( ft::make_pair( 233665123, 233665123) );         // std::cout << " i = " << i++ << std::endl; // i = 13
tree_picture_fluid(map_int);

map_int.insert( ft::make_pair( 468703135, 468703135) );         // std::cout << " i = " << i++ << std::endl; // i = 14
map_int.insert( ft::make_pair( 1801979802, 1801979802) );       // std::cout << " i = " << i++ << std::endl; // i = 15
map_int.insert( ft::make_pair( 635723058, 635723058) );         // std::cout << " i = " << i++ << std::endl; // i = 16
map_int.insert( ft::make_pair( 1125898167, 1125898167) );       // std::cout << " i = " << i++ << std::endl; // i = 17
map_int.insert( ft::make_pair( 2089018456, 2089018456) );       // std::cout << " i = " << i++ << std::endl; // i = 18
map_int.insert( ft::make_pair( 1656478042, 1656478042) );       // std::cout << " i = " << i++ << std::endl; // i = 19
map_int.insert( ft::make_pair( 1653377373, 1653377373) );       // std::cout << " i = " << i++ << std::endl; // i = 20
map_int.insert( ft::make_pair( 1914544919, 1914544919) );       // std::cout << " i = " << i++ << std::endl; // i = 21
map_int.insert( ft::make_pair( 756898537, 756898537) );         // std::cout << " i = " << i++ << std::endl; // i = 22
map_int.insert( ft::make_pair( 1973594324, 1973594324) );       // std::cout << " i = " << i++ << std::endl; // i = 23
map_int.insert( ft::make_pair( 2038664370, 2038664370) );       // std::cout << " i = " << i++ << std::endl; // i = 24
map_int.insert( ft::make_pair( 184803526, 184803526) );         // std::cout << " i = " << i++ << std::endl; // i = 25
map_int.insert( ft::make_pair( 1424268980, 1424268980) );       // std::cout << " i = " << i++ << std::endl; // i = 26
map_int.insert( ft::make_pair( 749241873, 749241873) );         // std::cout << " i = " << i++ << std::endl; // i = 27
map_int.insert( ft::make_pair( 42999170, 42999170) );           // std::cout << " i = " << i++ << std::endl; // i = 28
map_int.insert( ft::make_pair( 135497281, 135497281) );         // std::cout << " i = " << i++ << std::endl; // i = 29
map_int.insert( ft::make_pair( 2084420925, 2084420925) );       // std::cout << " i = " << i++ << std::endl; // i = 30
map_int.insert( ft::make_pair( 1827336327, 1827336327) );       // std::cout << " i = " << i++ << std::endl; // i = 31
map_int.insert( ft::make_pair( 1159126505, 1159126505) );       // std::cout << " i = " << i++ << std::endl; // i = 32
map_int.insert( ft::make_pair( 1632621729, 1632621729) );       // std::cout << " i = " << i++ << std::endl; // i = 33
map_int.insert( ft::make_pair( 1433925857, 1433925857) );       // std::cout << " i = " << i++ << std::endl; // i = 34
map_int.insert( ft::make_pair( 84353895, 84353895) );           // std::cout << " i = " << i++ << std::endl; // i = 35
map_int.insert( ft::make_pair( 2001100545, 2001100545) );       // std::cout << " i = " << i++ << std::endl; // i = 36
map_int.insert( ft::make_pair( 1548233367, 1548233367) );       // std::cout << " i = " << i++ << std::endl; // i = 37
map_int.insert( ft::make_pair( 1585990364, 1585990364) );       // std::cout << " i = " << i++ << std::endl; // i = 38
map_int.insert( ft::make_pair( 760313750, 760313750) );         // std::cout << " i = " << i++ << std::endl; // i = 39
map_int.insert( ft::make_pair( 356426808, 356426808) );         // std::cout << " i = " << i++ << std::endl; // i = 40
map_int.insert( ft::make_pair( 1889947178, 1889947178) );       // std::cout << " i = " << i++ << std::endl; // i = 41
map_int.insert( ft::make_pair( 709393584, 709393584) );         // std::cout << " i = " << i++ << std::endl; // i = 42
map_int.insert( ft::make_pair( 1918502651, 1918502651) );       // std::cout << " i = " << i++ << std::endl; // i = 43
map_int.insert( ft::make_pair( 1474612399, 1474612399) );       // std::cout << " i = " << i++ << std::endl; // i = 44
map_int.insert( ft::make_pair( 1264095060, 1264095060) );       // std::cout << " i = " << i++ << std::endl; // i = 45
map_int.insert( ft::make_pair( 1843993368, 1843993368) );       // std::cout << " i = " << i++ << std::endl; // i = 46
map_int.insert( ft::make_pair( 1984210012, 1984210012) );       // std::cout << " i = " << i++ << std::endl; // i = 47
map_int.insert( ft::make_pair( 1749698586, 1749698586) );       // std::cout << " i = " << i++ << std::endl; // i = 48
map_int.insert( ft::make_pair( 1956297539, 1956297539) );       // std::cout << " i = " << i++ << std::endl; // i = 49
map_int.insert( ft::make_pair( 463480570, 463480570) );         // std::cout << " i = " << i++ << std::endl; // i = 50
map_int.insert( ft::make_pair( 1975960378, 1975960378) );       // std::cout << " i = " << i++ << std::endl; // i = 51
map_int.insert( ft::make_pair( 1892066601, 1892066601) );       // std::cout << " i = " << i++ << std::endl; // i = 52
map_int.insert( ft::make_pair( 927612902, 927612902) );         // std::cout << " i = " << i++ << std::endl; // i = 53
map_int.insert( ft::make_pair( 603570492, 603570492) );         // std::cout << " i = " << i++ << std::endl; // i = 54
map_int.insert( ft::make_pair( 660260756, 660260756) );         // std::cout << " i = " << i++ << std::endl; // i = 55
map_int.insert( ft::make_pair( 485560280, 485560280) );         // std::cout << " i = " << i++ << std::endl; // i = 56
map_int.insert( ft::make_pair( 593209441, 593209441) );         // std::cout << " i = " << i++ << std::endl; // i = 57
map_int.insert( ft::make_pair( 894429689, 894429689) );         // std::cout << " i = " << i++ << std::endl; // i = 58
map_int.insert( ft::make_pair( 1947346619, 1947346619) );       // std::cout << " i = " << i++ << std::endl; // i = 59
map_int.insert( ft::make_pair( 270744729, 270744729) );         // std::cout << " i = " << i++ << std::endl; // i = 60
map_int.insert( ft::make_pair( 1633108117, 1633108117) );       // std::cout << " i = " << i++ << std::endl; // i = 61
map_int.insert( ft::make_pair( 2007905771, 2007905771) );       // std::cout << " i = " << i++ << std::endl; // i = 62
map_int.insert( ft::make_pair( 822890675, 822890675) );         // std::cout << " i = " << i++ << std::endl; // i = 63
map_int.insert( ft::make_pair( 791698927, 791698927) );         // std::cout << " i = " << i++ << std::endl; // i = 64
map_int.insert( ft::make_pair( 498777856, 498777856) );         // std::cout << " i = " << i++ << std::endl; // i = 65
map_int.insert( ft::make_pair( 524872353, 524872353) );         // std::cout << " i = " << i++ << std::endl; // i = 66
map_int.insert( ft::make_pair( 1572276965, 1572276965) );       // std::cout << " i = " << i++ << std::endl; // i = 67
map_int.insert( ft::make_pair( 1703964683, 1703964683) );       // std::cout << " i = " << i++ << std::endl; // i = 68
map_int.insert( ft::make_pair( 1600028624, 1600028624) );       // std::cout << " i = " << i++ << std::endl; // i = 69
map_int.insert( ft::make_pair( 2040332871, 2040332871) );       // std::cout << " i = " << i++ << std::endl; // i = 70
map_int.insert( ft::make_pair( 1120048829, 1120048829) );       // std::cout << " i = " << i++ << std::endl; // i = 71
map_int.insert( ft::make_pair( 515530019, 515530019) );         // std::cout << " i = " << i++ << std::endl; // i = 72
map_int.insert( ft::make_pair( 1573363368, 1573363368) );       // std::cout << " i = " << i++ << std::endl; // i = 73
map_int.insert( ft::make_pair( 2077486715, 2077486715) );       // std::cout << " i = " << i++ << std::endl; // i = 74
map_int.insert( ft::make_pair( 1631518149, 1631518149) );       // std::cout << " i = " << i++ << std::endl; // i = 75
map_int.insert( ft::make_pair( 289700723, 289700723) );         // std::cout << " i = " << i++ << std::endl; // i = 76
map_int.insert( ft::make_pair( 168002245, 168002245) );         // std::cout << " i = " << i++ << std::endl; // i = 77
map_int.insert( ft::make_pair( 439493451, 439493451) );         // std::cout << " i = " << i++ << std::endl; // i = 78
map_int.insert( ft::make_pair( 1760243555, 1760243555) );       // std::cout << " i = " << i++ << std::endl; // i = 79
map_int.insert( ft::make_pair( 1622597488, 1622597488) );       // std::cout << " i = " << i++ << std::endl; // i = 80
map_int.insert( ft::make_pair( 338888228, 338888228) );         // std::cout << " i = " << i++ << std::endl; // i = 81
map_int.insert( ft::make_pair( 438792350, 438792350) );         // std::cout << " i = " << i++ << std::endl; // i = 82
map_int.insert( ft::make_pair( 269441500, 269441500) );         // std::cout << " i = " << i++ << std::endl; // i = 83
map_int.insert( ft::make_pair( 116087764, 116087764) );         // std::cout << " i = " << i++ << std::endl; // i = 84
map_int.insert( ft::make_pair( 155324914, 155324914) );         // std::cout << " i = " << i++ << std::endl; // i = 85
map_int.insert( ft::make_pair( 1982275856, 1982275856) );       // std::cout << " i = " << i++ << std::endl; // i = 86
map_int.insert( ft::make_pair( 387346491, 387346491) );         // std::cout << " i = " << i++ << std::endl; // i = 87
map_int.insert( ft::make_pair( 841148365, 841148365) );         // std::cout << " i = " << i++ << std::endl; // i = 88
map_int.insert( ft::make_pair( 1760281936, 1760281936) );       // std::cout << " i = " << i++ << std::endl; // i = 89
map_int.insert( ft::make_pair( 1186452551, 1186452551) );       // std::cout << " i = " << i++ << std::endl; // i = 90
map_int.insert( ft::make_pair( 971899228, 971899228) );         // std::cout << " i = " << i++ << std::endl; // i = 91
map_int.insert( ft::make_pair( 213975407, 213975407) );         // std::cout << " i = " << i++ << std::endl; // i = 92
map_int.insert( ft::make_pair( 1626276121, 1626276121) );       // std::cout << " i = " << i++ << std::endl; // i = 93
map_int.insert( ft::make_pair( 2130794395, 2130794395) );       // std::cout << " i = " << i++ << std::endl; // i = 94
map_int.insert( ft::make_pair( 1884661237, 1884661237) );       // std::cout << " i = " << i++ << std::endl; // i = 95
map_int.insert( ft::make_pair( 1350573793, 1350573793) );       // std::cout << " i = " << i++ << std::endl; // i = 96
map_int.insert( ft::make_pair( 1605894428, 1605894428) );       // std::cout << " i = " << i++ << std::endl; // i = 97
map_int.insert( ft::make_pair( 1987231011, 1987231011) );       // std::cout << " i = " << i++ << std::endl; // i = 98
map_int.insert( ft::make_pair( 1784639529, 1784639529) );       // std::cout << " i = " << i++ << std::endl; // i = 99
map_int.insert( ft::make_pair( 1597322404, 1597322404) );       // std::cout << " i = " << i++ << std::endl; // i = 100
map_int.insert( ft::make_pair( 2112255763, 2112255763) );       // std::cout << " i = " << i++ << std::endl; // i = 101
map_int.insert( ft::make_pair( 1067854538, 1067854538) );       // std::cout << " i = " << i++ << std::endl; // i = 102
map_int.insert( ft::make_pair( 1782436840, 1782436840) );       // std::cout << " i = " << i++ << std::endl; // i = 103
map_int.insert( ft::make_pair( 165344818, 165344818) );         // std::cout << " i = " << i++ << std::endl; // i = 104
map_int.insert( ft::make_pair( 532670688, 532670688) );         // std::cout << " i = " << i++ << std::endl; // i = 105
map_int.insert( ft::make_pair( 492067917, 492067917) );         // std::cout << " i = " << i++ << std::endl; // i = 106
map_int.insert( ft::make_pair( 680466996, 680466996) );         // std::cout << " i = " << i++ << std::endl; // i = 107
map_int.insert( ft::make_pair( 496987743, 496987743) );         // std::cout << " i = " << i++ << std::endl; // i = 108
map_int.insert( ft::make_pair( 1359512183, 1359512183) );       // std::cout << " i = " << i++ << std::endl; // i = 109
map_int.insert( ft::make_pair( 1398295499, 1398295499) );       // std::cout << " i = " << i++ << std::endl; // i = 110
map_int.insert( ft::make_pair( 2086206725, 2086206725) );       // std::cout << " i = " << i++ << std::endl; // i = 111
map_int.insert( ft::make_pair( 1172755590, 1172755590) );       // std::cout << " i = " << i++ << std::endl; // i = 112
map_int.insert( ft::make_pair( 243268139, 243268139) );         // std::cout << " i = " << i++ << std::endl; // i = 113
map_int.insert( ft::make_pair( 1272469786, 1272469786) );       // std::cout << " i = " << i++ << std::endl; // i = 114
map_int.insert( ft::make_pair( 968338082, 968338082) );         // std::cout << " i = " << i++ << std::endl; // i = 115
map_int.insert( ft::make_pair( 1820388464, 1820388464) );       // std::cout << " i = " << i++ << std::endl; // i = 116
map_int.insert( ft::make_pair( 6939507, 6939507) );             // std::cout << " i = " << i++ << std::endl; // i = 117
map_int.insert( ft::make_pair( 1285228804, 1285228804) );       // std::cout << " i = " << i++ << std::endl; // i = 118
map_int.insert( ft::make_pair( 502278611, 502278611) );         // std::cout << " i = " << i++ << std::endl; // i = 119
map_int.insert( ft::make_pair( 1037127828, 1037127828) );       // std::cout << " i = " << i++ << std::endl; // i = 120
map_int.insert( ft::make_pair( 654887343, 654887343) );         // std::cout << " i = " << i++ << std::endl; // i = 121
map_int.insert( ft::make_pair( 392035568, 392035568) );         // std::cout << " i = " << i++ << std::endl; // i = 122
map_int.insert( ft::make_pair( 87755422, 87755422) );           // std::cout << " i = " << i++ << std::endl; // i = 123
map_int.insert( ft::make_pair( 1494613810, 1494613810) );       // std::cout << " i = " << i++ << std::endl; // i = 124
map_int.insert( ft::make_pair( 1369321801, 1369321801) );       // std::cout << " i = " << i++ << std::endl; // i = 125
map_int.insert( ft::make_pair( 396473730, 396473730) );         // std::cout << " i = " << i++ << std::endl; // i = 126
map_int.insert( ft::make_pair( 1346811305, 1346811305) );       // std::cout << " i = " << i++ << std::endl; // i = 127
map_int.insert( ft::make_pair( 705178736, 705178736) );         // std::cout << " i = " << i++ << std::endl; // i = 128
map_int.insert( ft::make_pair( 434248626, 434248626) );         // std::cout << " i = " << i++ << std::endl; // i = 129
map_int.insert( ft::make_pair( 1470503465, 1470503465) );       // std::cout << " i = " << i++ << std::endl; // i = 130
map_int.insert( ft::make_pair( 552473416, 552473416) );         // std::cout << " i = " << i++ << std::endl; // i = 131
map_int.insert( ft::make_pair( 188213258, 188213258) );         // std::cout << " i = " << i++ << std::endl; // i = 132
map_int.insert( ft::make_pair( 1884167637, 1884167637) );       // std::cout << " i = " << i++ << std::endl; // i = 133
map_int.insert( ft::make_pair( 201305624, 201305624) );         // std::cout << " i = " << i++ << std::endl; // i = 134
map_int.insert( ft::make_pair( 776532036, 776532036) );         // std::cout << " i = " << i++ << std::endl; // i = 135
map_int.insert( ft::make_pair( 1273911899, 1273911899) );       // std::cout << " i = " << i++ << std::endl; // i = 136
map_int.insert( ft::make_pair( 620145550, 620145550) );         // std::cout << " i = " << i++ << std::endl; // i = 137
map_int.insert( ft::make_pair( 619290071, 619290071) );         // std::cout << " i = " << i++ << std::endl; // i = 138
map_int.insert( ft::make_pair( 407487131, 407487131) );         // std::cout << " i = " << i++ << std::endl; // i = 139
map_int.insert( ft::make_pair( 7684930, 7684930) );             // std::cout << " i = " << i++ << std::endl; // i = 140
map_int.insert( ft::make_pair( 711845894, 711845894) );         // std::cout << " i = " << i++ << std::endl; // i = 141
map_int.insert( ft::make_pair( 937370163, 937370163) );         // std::cout << " i = " << i++ << std::endl; // i = 142
map_int.insert( ft::make_pair( 1973387981, 1973387981) );       // std::cout << " i = " << i++ << std::endl; // i = 143
map_int.insert( ft::make_pair( 1501252996, 1501252996) );       // std::cout << " i = " << i++ << std::endl; // i = 144
map_int.insert( ft::make_pair( 1472713773, 1472713773) );       // std::cout << " i = " << i++ << std::endl; // i = 145
map_int.insert( ft::make_pair( 1662739668, 1662739668) );       // std::cout << " i = " << i++ << std::endl; // i = 146
map_int.insert( ft::make_pair( 1967681095, 1967681095) );       // std::cout << " i = " << i++ << std::endl; // i = 147
map_int.insert( ft::make_pair( 437116466, 437116466) );         // std::cout << " i = " << i++ << std::endl; // i = 148
map_int.insert( ft::make_pair( 1176911340, 1176911340) );       // std::cout << " i = " << i++ << std::endl; // i = 149
map_int.insert( ft::make_pair( 1943327684, 1943327684) );       // std::cout << " i = " << i++ << std::endl; // i = 150
map_int.insert( ft::make_pair( 1876855542, 1876855542) );       // std::cout << " i = " << i++ << std::endl; // i = 151
map_int.insert( ft::make_pair( 1237379107, 1237379107) );       // std::cout << " i = " << i++ << std::endl; // i = 152
map_int.insert( ft::make_pair( 588219756, 588219756) );         // std::cout << " i = " << i++ << std::endl; // i = 153
map_int.insert( ft::make_pair( 1057418418, 1057418418) );       // std::cout << " i = " << i++ << std::endl; // i = 154
map_int.insert( ft::make_pair( 1823089412, 1823089412) );       // std::cout << " i = " << i++ << std::endl; // i = 155
map_int.insert( ft::make_pair( 625032172, 625032172) );         // std::cout << " i = " << i++ << std::endl; // i = 156
map_int.insert( ft::make_pair( 1469262009, 1469262009) );       // std::cout << " i = " << i++ << std::endl; // i = 157
map_int.insert( ft::make_pair( 298625210, 298625210) );         // std::cout << " i = " << i++ << std::endl; // i = 158
map_int.insert( ft::make_pair( 1057467587, 1057467587) );       // std::cout << " i = " << i++ << std::endl; // i = 159
map_int.insert( ft::make_pair( 1555319301, 1555319301) );       // std::cout << " i = " << i++ << std::endl; // i = 160
map_int.insert( ft::make_pair( 476667372, 476667372) );         // std::cout << " i = " << i++ << std::endl; // i = 161
map_int.insert( ft::make_pair( 260401255, 260401255) );         // std::cout << " i = " << i++ << std::endl; // i = 162
map_int.insert( ft::make_pair( 774044599, 774044599) );         // std::cout << " i = " << i++ << std::endl; // i = 163
map_int.insert( ft::make_pair( 2001229904, 2001229904) );       // std::cout << " i = " << i++ << std::endl; // i = 164
map_int.insert( ft::make_pair( 1335939811, 1335939811) );       // std::cout << " i = " << i++ << std::endl; // i = 165
map_int.insert( ft::make_pair( 1756915667, 1756915667) );       // std::cout << " i = " << i++ << std::endl; // i = 166
map_int.insert( ft::make_pair( 719346228, 719346228) );         // std::cout << " i = " << i++ << std::endl; // i = 167
map_int.insert( ft::make_pair( 1414829150, 1414829150) );       // std::cout << " i = " << i++ << std::endl; // i = 168
map_int.insert( ft::make_pair( 555996658, 555996658) );         // std::cout << " i = " << i++ << std::endl; // i = 169
map_int.insert( ft::make_pair( 155789224, 155789224) );         // std::cout << " i = " << i++ << std::endl; // i = 170
map_int.insert( ft::make_pair( 1389867269, 1389867269) );       // std::cout << " i = " << i++ << std::endl; // i = 171
map_int.insert( ft::make_pair( 619054081, 619054081) );         // std::cout << " i = " << i++ << std::endl; // i = 172
map_int.insert( ft::make_pair( 195740084, 195740084) );         // std::cout << " i = " << i++ << std::endl; // i = 173
map_int.insert( ft::make_pair( 2006811972, 2006811972) );       // std::cout << " i = " << i++ << std::endl; // i = 174
map_int.insert( ft::make_pair( 570073850, 570073850) );         // std::cout << " i = " << i++ << std::endl; // i = 175
map_int.insert( ft::make_pair( 1635905385, 1635905385) );       // std::cout << " i = " << i++ << std::endl; // i = 176
map_int.insert( ft::make_pair( 337739299, 337739299) );         // std::cout << " i = " << i++ << std::endl; // i = 177
map_int.insert( ft::make_pair( 1343606042, 1343606042) );       // std::cout << " i = " << i++ << std::endl; // i = 178
map_int.insert( ft::make_pair( 446340713, 446340713) );         // std::cout << " i = " << i++ << std::endl; // i = 179
map_int.insert( ft::make_pair( 915256190, 915256190) );         // std::cout << " i = " << i++ << std::endl; // i = 180
map_int.insert( ft::make_pair( 846942590, 846942590) );         // std::cout << " i = " << i++ << std::endl; // i = 181
map_int.insert( ft::make_pair( 700108581, 700108581) );         // std::cout << " i = " << i++ << std::endl; // i = 182
map_int.insert( ft::make_pair( 1371499336, 1371499336) );       // std::cout << " i = " << i++ << std::endl; // i = 183
map_int.insert( ft::make_pair( 726371155, 726371155) );         // std::cout << " i = " << i++ << std::endl; // i = 184
map_int.insert( ft::make_pair( 292218004, 292218004) );         // std::cout << " i = " << i++ << std::endl; // i = 185
map_int.insert( ft::make_pair( 11614769, 11614769) );           // std::cout << " i = " << i++ << std::endl; // i = 186
map_int.insert( ft::make_pair( 1662981776, 1662981776) );       // std::cout << " i = " << i++ << std::endl; // i = 187
map_int.insert( ft::make_pair( 246247255, 246247255) );         // std::cout << " i = " << i++ << std::endl; // i = 188
map_int.insert( ft::make_pair( 1548348142, 1548348142) );       // std::cout << " i = " << i++ << std::endl; // i = 189
map_int.insert( ft::make_pair( 964445884, 964445884) );         // std::cout << " i = " << i++ << std::endl; // i = 190
map_int.insert( ft::make_pair( 1520223205, 1520223205) );       // std::cout << " i = " << i++ << std::endl; // i = 191
map_int.insert( ft::make_pair( 1017679567, 1017679567) );       // std::cout << " i = " << i++ << std::endl; // i = 192
map_int.insert( ft::make_pair( 201690613, 201690613) );         // std::cout << " i = " << i++ << std::endl; // i = 193
map_int.insert( ft::make_pair( 822262754, 822262754) );         // std::cout << " i = " << i++ << std::endl; // i = 194
map_int.insert( ft::make_pair( 1411154259, 1411154259) );       // std::cout << " i = " << i++ << std::endl; // i = 195
map_int.insert( ft::make_pair( 282828202, 282828202) );         // std::cout << " i = " << i++ << std::endl; // i = 196
map_int.insert( ft::make_pair( 114723506, 114723506) );         // std::cout << " i = " << i++ << std::endl; // i = 197
map_int.insert( ft::make_pair( 1676902021, 1676902021) );       // std::cout << " i = " << i++ << std::endl; // i = 198
map_int.insert( ft::make_pair( 950390868, 950390868) );         // std::cout << " i = " << i++ << std::endl; // i = 199
map_int.insert( ft::make_pair( 1266235189, 1266235189) );       // std::cout << " i = " << i++ << std::endl; // i = 200
map_int.insert( ft::make_pair( 1137949908, 1137949908) );       // std::cout << " i = " << i++ << std::endl; // i = 201
map_int.insert( ft::make_pair( 777210498, 777210498) );         // std::cout << " i = " << i++ << std::endl; // i = 202
map_int.insert( ft::make_pair( 1908518808, 1908518808) );       // std::cout << " i = " << i++ << std::endl; // i = 203
map_int.insert( ft::make_pair( 364686248, 364686248) );         // std::cout << " i = " << i++ << std::endl; // i = 204
map_int.insert( ft::make_pair( 1129033333, 1129033333) );       // std::cout << " i = " << i++ << std::endl; // i = 205
map_int.insert( ft::make_pair( 1280321648, 1280321648) );       // std::cout << " i = " << i++ << std::endl; // i = 206
map_int.insert( ft::make_pair( 1781999754, 1781999754) );       // std::cout << " i = " << i++ << std::endl; // i = 207
map_int.insert( ft::make_pair( 212251746, 212251746) );         // std::cout << " i = " << i++ << std::endl; // i = 208
map_int.insert( ft::make_pair( 364319529, 364319529) );         // std::cout << " i = " << i++ << std::endl; // i = 209
map_int.insert( ft::make_pair( 484238046, 484238046) );         // std::cout << " i = " << i++ << std::endl; // i = 210
map_int.insert( ft::make_pair( 624549797, 624549797) );         // std::cout << " i = " << i++ << std::endl; // i = 211
map_int.insert( ft::make_pair( 1886086990, 1886086990) );       // std::cout << " i = " << i++ << std::endl; // i = 212
map_int.insert( ft::make_pair( 1750003033, 1750003033) );       // std::cout << " i = " << i++ << std::endl; // i = 213
map_int.insert( ft::make_pair( 78012497, 78012497) );           // std::cout << " i = " << i++ << std::endl; // i = 214
map_int.insert( ft::make_pair( 1671294892, 1671294892) );       // std::cout << " i = " << i++ << std::endl; // i = 215
map_int.insert( ft::make_pair( 1795519125, 1795519125) );       // std::cout << " i = " << i++ << std::endl; // i = 216
map_int.insert( ft::make_pair( 474613996, 474613996) );         // std::cout << " i = " << i++ << std::endl; // i = 217
map_int.insert( ft::make_pair( 1315209188, 1315209188) );       // std::cout << " i = " << i++ << std::endl; // i = 218
map_int.insert( ft::make_pair( 1448703729, 1448703729) );       // std::cout << " i = " << i++ << std::endl; // i = 219
map_int.insert( ft::make_pair( 1545032460, 1545032460) );       // std::cout << " i = " << i++ << std::endl; // i = 220
map_int.insert( ft::make_pair( 861543921, 861543921) );         // std::cout << " i = " << i++ << std::endl; // i = 221
map_int.insert( ft::make_pair( 932026304, 932026304) );         // std::cout << " i = " << i++ << std::endl; // i = 222
map_int.insert( ft::make_pair( 828388027, 828388027) );         // std::cout << " i = " << i++ << std::endl; // i = 223
map_int.insert( ft::make_pair( 332266748, 332266748) );         // std::cout << " i = " << i++ << std::endl; // i = 224
map_int.insert( ft::make_pair( 31308902, 31308902) );           // std::cout << " i = " << i++ << std::endl; // i = 225
map_int.insert( ft::make_pair( 820697697, 820697697) );         // std::cout << " i = " << i++ << std::endl; // i = 226
map_int.insert( ft::make_pair( 1583571043, 1583571043) );       // std::cout << " i = " << i++ << std::endl; // i = 227
map_int.insert( ft::make_pair( 1395132002, 1395132002) );       // std::cout << " i = " << i++ << std::endl; // i = 228
map_int.insert( ft::make_pair( 1974806403, 1974806403) );       // std::cout << " i = " << i++ << std::endl; // i = 229
map_int.insert( ft::make_pair( 1739000681, 1739000681) );       // std::cout << " i = " << i++ << std::endl; // i = 230
map_int.insert( ft::make_pair( 669908538, 669908538) );         // std::cout << " i = " << i++ << std::endl; // i = 231
map_int.insert( ft::make_pair( 12895151, 12895151) );           // std::cout << " i = " << i++ << std::endl; // i = 232
map_int.insert( ft::make_pair( 1812282134, 1812282134) );       // std::cout << " i = " << i++ << std::endl; // i = 233
map_int.insert( ft::make_pair( 1380171692, 1380171692) );       // std::cout << " i = " << i++ << std::endl; // i = 234
map_int.insert( ft::make_pair( 860516127, 860516127) );         // std::cout << " i = " << i++ << std::endl; // i = 235
map_int.insert( ft::make_pair( 1543755629, 1543755629) );       // std::cout << " i = " << i++ << std::endl; // i = 236
map_int.insert( ft::make_pair( 1455590964, 1455590964) );       // std::cout << " i = " << i++ << std::endl; // i = 237
map_int.insert( ft::make_pair( 70636429, 70636429) );           // std::cout << " i = " << i++ << std::endl; // i = 238
map_int.insert( ft::make_pair( 1472576335, 1472576335) );       // std::cout << " i = " << i++ << std::endl; // i = 239
map_int.insert( ft::make_pair( 1329202900, 1329202900) );       // std::cout << " i = " << i++ << std::endl; // i = 240
map_int.insert( ft::make_pair( 1219407971, 1219407971) );       // std::cout << " i = " << i++ << std::endl; // i = 241
map_int.insert( ft::make_pair( 12260289, 12260289) );           // std::cout << " i = " << i++ << std::endl; // i = 242
map_int.insert( ft::make_pair( 561717988, 561717988) );         // std::cout << " i = " << i++ << std::endl; // i = 243
map_int.insert( ft::make_pair( 1841585795, 1841585795) );       // std::cout << " i = " << i++ << std::endl; // i = 244
map_int.insert( ft::make_pair( 733053144, 733053144) );         // std::cout << " i = " << i++ << std::endl; // i = 245
map_int.insert( ft::make_pair( 1887658390, 1887658390) );       // std::cout << " i = " << i++ << std::endl; // i = 246
map_int.insert( ft::make_pair( 672655340, 672655340) );         // std::cout << " i = " << i++ << std::endl; // i = 247
map_int.insert( ft::make_pair( 400000569, 400000569) );         // std::cout << " i = " << i++ << std::endl; // i = 248
map_int.insert( ft::make_pair( 1081174232, 1081174232) );       // std::cout << " i = " << i++ << std::endl; // i = 249
map_int.insert( ft::make_pair( 1450956042, 1450956042) );       // std::cout << " i = " << i++ << std::endl; // i = 250
map_int.insert( ft::make_pair( 410409117, 410409117) );         // std::cout << " i = " << i++ << std::endl; // i = 251
map_int.insert( ft::make_pair( 1516266761, 1516266761) );       // std::cout << " i = " << i++ << std::endl; // i = 252
map_int.insert( ft::make_pair( 1175526309, 1175526309) );       // std::cout << " i = " << i++ << std::endl; // i = 253
map_int.insert( ft::make_pair( 2002495425, 2002495425) );       // std::cout << " i = " << i++ << std::endl; // i = 254
map_int.insert( ft::make_pair( 1989806367, 1989806367) );       // std::cout << " i = " << i++ << std::endl; // i = 255
map_int.insert( ft::make_pair( 2004504234, 2004504234) );       // std::cout << " i = " << i++ << std::endl; // i = 256
map_int.insert( ft::make_pair( 1186631626, 1186631626) );       // std::cout << " i = " << i++ << std::endl; // i = 257
map_int.insert( ft::make_pair( 1717226057, 1717226057) );       // std::cout << " i = " << i++ << std::endl; // i = 258
map_int.insert( ft::make_pair( 1276673168, 1276673168) );       // std::cout << " i = " << i++ << std::endl; // i = 259
map_int.insert( ft::make_pair( 2137390358, 2137390358) );       // std::cout << " i = " << i++ << std::endl; // i = 260
map_int.insert( ft::make_pair( 696947386, 696947386) );         // std::cout << " i = " << i++ << std::endl; // i = 261
map_int.insert( ft::make_pair( 1265204346, 1265204346) );       // std::cout << " i = " << i++ << std::endl; // i = 262
map_int.insert( ft::make_pair( 1630634994, 1630634994) );       // std::cout << " i = " << i++ << std::endl; // i = 263
map_int.insert( ft::make_pair( 1707056552, 1707056552) );       // std::cout << " i = " << i++ << std::endl; // i = 264
map_int.insert( ft::make_pair( 1297893529, 1297893529) );       // std::cout << " i = " << i++ << std::endl; // i = 265
map_int.insert( ft::make_pair( 358532290, 358532290) );         // std::cout << " i = " << i++ << std::endl; // i = 266
map_int.insert( ft::make_pair( 1857756970, 1857756970) );       // std::cout << " i = " << i++ << std::endl; // i = 267
map_int.insert( ft::make_pair( 1426819080, 1426819080) );       // std::cout << " i = " << i++ << std::endl; // i = 268
map_int.insert( ft::make_pair( 1314218593, 1314218593) );       // std::cout << " i = " << i++ << std::endl; // i = 269
map_int.insert( ft::make_pair( 1386418627, 1386418627) );       // std::cout << " i = " << i++ << std::endl; // i = 270
map_int.insert( ft::make_pair( 318561886, 318561886) );         // std::cout << " i = " << i++ << std::endl; // i = 271
map_int.insert( ft::make_pair( 70788355, 70788355) );           // std::cout << " i = " << i++ << std::endl; // i = 272
map_int.insert( ft::make_pair( 1112720090, 1112720090) );       // std::cout << " i = " << i++ << std::endl; // i = 273
map_int.insert( ft::make_pair( 1106059479, 1106059479) );       // std::cout << " i = " << i++ << std::endl; // i = 274
map_int.insert( ft::make_pair( 1051858969, 1051858969) );       // std::cout << " i = " << i++ << std::endl; // i = 275
map_int.insert( ft::make_pair( 104152274, 104152274) );         // std::cout << " i = " << i++ << std::endl; // i = 276
map_int.insert( ft::make_pair( 826047641, 826047641) );         // std::cout << " i = " << i++ << std::endl; // i = 277
map_int.insert( ft::make_pair( 970925433, 970925433) );         // std::cout << " i = " << i++ << std::endl; // i = 278
map_int.insert( ft::make_pair( 887077888, 887077888) );         // std::cout << " i = " << i++ << std::endl; // i = 279
map_int.insert( ft::make_pair( 873524566, 873524566) );         // std::cout << " i = " << i++ << std::endl; // i = 280
map_int.insert( ft::make_pair( 1541027284, 1541027284) );       // std::cout << " i = " << i++ << std::endl; // i = 281
map_int.insert( ft::make_pair( 1745790417, 1745790417) );       // std::cout << " i = " << i++ << std::endl; // i = 282
map_int.insert( ft::make_pair( 959372260, 959372260) );         // std::cout << " i = " << i++ << std::endl; // i = 283
map_int.insert( ft::make_pair( 2137100237, 2137100237) );       // std::cout << " i = " << i++ << std::endl; // i = 284
map_int.insert( ft::make_pair( 159473059, 159473059) );         // std::cout << " i = " << i++ << std::endl; // i = 285
map_int.insert( ft::make_pair( 1282648518, 1282648518) );       // std::cout << " i = " << i++ << std::endl; // i = 286
map_int.insert( ft::make_pair( 471990783, 471990783) );         // std::cout << " i = " << i++ << std::endl; // i = 287
map_int.insert( ft::make_pair( 1983228458, 1983228458) );       // std::cout << " i = " << i++ << std::endl; // i = 288
map_int.insert( ft::make_pair( 993967637, 993967637) );         // std::cout << " i = " << i++ << std::endl; // i = 289
map_int.insert( ft::make_pair( 1826620483, 1826620483) );       // std::cout << " i = " << i++ << std::endl; // i = 290
map_int.insert( ft::make_pair( 2037770478, 2037770478) );       // std::cout << " i = " << i++ << std::endl; // i = 291
map_int.insert( ft::make_pair( 1647149314, 1647149314) );       // std::cout << " i = " << i++ << std::endl; // i = 292
map_int.insert( ft::make_pair( 1152645729, 1152645729) );       // std::cout << " i = " << i++ << std::endl; // i = 293
map_int.insert( ft::make_pair( 1025533459, 1025533459) );       // std::cout << " i = " << i++ << std::endl; // i = 294
map_int.insert( ft::make_pair( 1001089438, 1001089438) );       // std::cout << " i = " << i++ << std::endl; // i = 295
map_int.insert( ft::make_pair( 2077211388, 2077211388) );       // std::cout << " i = " << i++ << std::endl; // i = 296
map_int.insert( ft::make_pair( 983631233, 983631233) );         // std::cout << " i = " << i++ << std::endl; // i = 297
map_int.insert( ft::make_pair( 1645933681, 1645933681) );       // std::cout << " i = " << i++ << std::endl; // i = 298
map_int.insert( ft::make_pair( 553160358, 553160358) );         // std::cout << " i = " << i++ << std::endl; // i = 299
map_int.insert( ft::make_pair( 2069110699, 2069110699) );       // std::cout << " i = " << i++ << std::endl; // i = 300
map_int.insert( ft::make_pair( 864101839, 864101839) );         // std::cout << " i = " << i++ << std::endl; // i = 301
map_int.insert( ft::make_pair( 1190668363, 1190668363) );       // std::cout << " i = " << i++ << std::endl; // i = 302
map_int.insert( ft::make_pair( 410228794, 410228794) );         // std::cout << " i = " << i++ << std::endl; // i = 303
map_int.insert( ft::make_pair( 773319847, 773319847) );         // std::cout << " i = " << i++ << std::endl; // i = 304
map_int.insert( ft::make_pair( 1968217462, 1968217462) );       // std::cout << " i = " << i++ << std::endl; // i = 305
map_int.insert( ft::make_pair( 1302539390, 1302539390) );       // std::cout << " i = " << i++ << std::endl; // i = 306
map_int.insert( ft::make_pair( 235745791, 235745791) );         // std::cout << " i = " << i++ << std::endl; // i = 307
map_int.insert( ft::make_pair( 427355115, 427355115) );         // std::cout << " i = " << i++ << std::endl; // i = 308
map_int.insert( ft::make_pair( 1272796157, 1272796157) );       // std::cout << " i = " << i++ << std::endl; // i = 309
map_int.insert( ft::make_pair( 1280631491, 1280631491) );       // std::cout << " i = " << i++ << std::endl; // i = 310
map_int.insert( ft::make_pair( 1204462951, 1204462951) );       // std::cout << " i = " << i++ << std::endl; // i = 311
map_int.insert( ft::make_pair( 521035021, 521035021) );         // std::cout << " i = " << i++ << std::endl; // i = 312
map_int.insert( ft::make_pair( 738393740, 738393740) );         // std::cout << " i = " << i++ << std::endl; // i = 313
map_int.insert( ft::make_pair( 1983614030, 1983614030) );       // std::cout << " i = " << i++ << std::endl; // i = 314
map_int.insert( ft::make_pair( 1655035325, 1655035325) );       // std::cout << " i = " << i++ << std::endl; // i = 315
map_int.insert( ft::make_pair( 2004187516, 2004187516) );       // std::cout << " i = " << i++ << std::endl; // i = 316
map_int.insert( ft::make_pair( 962033002, 962033002) );         // std::cout << " i = " << i++ << std::endl; // i = 317
map_int.insert( ft::make_pair( 1707746139, 1707746139) );       // std::cout << " i = " << i++ << std::endl; // i = 318
map_int.insert( ft::make_pair( 2073785404, 2073785404) );       // std::cout << " i = " << i++ << std::endl; // i = 319
map_int.insert( ft::make_pair( 628974580, 628974580) );         // std::cout << " i = " << i++ << std::endl; // i = 320
map_int.insert( ft::make_pair( 786039021, 786039021) );         // std::cout << " i = " << i++ << std::endl; // i = 321
map_int.insert( ft::make_pair( 1605539862, 1605539862) );       // std::cout << " i = " << i++ << std::endl; // i = 322
map_int.insert( ft::make_pair( 586235379, 586235379) );         // std::cout << " i = " << i++ << std::endl; // i = 323
map_int.insert( ft::make_pair( 262692685, 262692685) );         // std::cout << " i = " << i++ << std::endl; // i = 324
map_int.insert( ft::make_pair( 1338299904, 1338299904) );       // std::cout << " i = " << i++ << std::endl; // i = 325
map_int.insert( ft::make_pair( 1985433483, 1985433483) );       // std::cout << " i = " << i++ << std::endl; // i = 326
map_int.insert( ft::make_pair( 606199759, 606199759) );         // std::cout << " i = " << i++ << std::endl; // i = 327
map_int.insert( ft::make_pair( 435889744, 435889744) );         // std::cout << " i = " << i++ << std::endl; // i = 328
map_int.insert( ft::make_pair( 378469911, 378469911) );         // std::cout << " i = " << i++ << std::endl; // i = 329
map_int.insert( ft::make_pair( 488663950, 488663950) );         // std::cout << " i = " << i++ << std::endl; // i = 330
map_int.insert( ft::make_pair( 29777560, 29777560) );           // std::cout << " i = " << i++ << std::endl; // i = 331
map_int.insert( ft::make_pair( 257675105, 257675105) );         // std::cout << " i = " << i++ << std::endl; // i = 332
map_int.insert( ft::make_pair( 1392740049, 1392740049) );       // std::cout << " i = " << i++ << std::endl; // i = 333
map_int.insert( ft::make_pair( 216588711, 216588711) );         // std::cout << " i = " << i++ << std::endl; // i = 334
map_int.insert( ft::make_pair( 151519934, 151519934) );         // std::cout << " i = " << i++ << std::endl; // i = 335
map_int.insert( ft::make_pair( 1066077375, 1066077375) );       // std::cout << " i = " << i++ << std::endl; // i = 336
map_int.insert( ft::make_pair( 629593614, 629593614) );         // std::cout << " i = " << i++ << std::endl; // i = 337
map_int.insert( ft::make_pair( 1959343768, 1959343768) );       // std::cout << " i = " << i++ << std::endl; // i = 338
map_int.insert( ft::make_pair( 409544918, 409544918) );         // std::cout << " i = " << i++ << std::endl; // i = 339
map_int.insert( ft::make_pair( 927376882, 927376882) );         // std::cout << " i = " << i++ << std::endl; // i = 340
map_int.insert( ft::make_pair( 1617876982, 1617876982) );       // std::cout << " i = " << i++ << std::endl; // i = 341
map_int.insert( ft::make_pair( 2143124030, 2143124030) );       // std::cout << " i = " << i++ << std::endl; // i = 342
map_int.insert( ft::make_pair( 1124311574, 1124311574) );       // std::cout << " i = " << i++ << std::endl; // i = 343
map_int.insert( ft::make_pair( 1421186593, 1421186593) );       // std::cout << " i = " << i++ << std::endl; // i = 344
map_int.insert( ft::make_pair( 703550253, 703550253) );         // std::cout << " i = " << i++ << std::endl; // i = 345
map_int.insert( ft::make_pair( 1388803074, 1388803074) );       // std::cout << " i = " << i++ << std::endl; // i = 346
map_int.insert( ft::make_pair( 107734713, 107734713) );         // std::cout << " i = " << i++ << std::endl; // i = 347
map_int.insert( ft::make_pair( 1725138377, 1725138377) );       // std::cout << " i = " << i++ << std::endl; // i = 348
map_int.insert( ft::make_pair( 1464415775, 1464415775) );       // std::cout << " i = " << i++ << std::endl; // i = 349
map_int.insert( ft::make_pair( 672032919, 672032919) );         // std::cout << " i = " << i++ << std::endl; // i = 350
map_int.insert( ft::make_pair( 639806732, 639806732) );         // std::cout << " i = " << i++ << std::endl; // i = 351
map_int.insert( ft::make_pair( 406011017, 406011017) );         // std::cout << " i = " << i++ << std::endl; // i = 352
map_int.insert( ft::make_pair( 114760235, 114760235) );         // std::cout << " i = " << i++ << std::endl; // i = 353
map_int.insert( ft::make_pair( 337745691, 337745691) );         // std::cout << " i = " << i++ << std::endl; // i = 354
map_int.insert( ft::make_pair( 292423943, 292423943) );         // std::cout << " i = " << i++ << std::endl; // i = 355
map_int.insert( ft::make_pair( 124666328, 124666328) );         // std::cout << " i = " << i++ << std::endl; // i = 356
map_int.insert( ft::make_pair( 2030449291, 2030449291) );       // std::cout << " i = " << i++ << std::endl; // i = 357
map_int.insert( ft::make_pair( 1986894018, 1986894018) );       // std::cout << " i = " << i++ << std::endl; // i = 358
map_int.insert( ft::make_pair( 551836836, 551836836) );         // std::cout << " i = " << i++ << std::endl; // i = 359
map_int.insert( ft::make_pair( 362575055, 362575055) );         // std::cout << " i = " << i++ << std::endl; // i = 360
map_int.insert( ft::make_pair( 1022963858, 1022963858) );       // std::cout << " i = " << i++ << std::endl; // i = 361
map_int.insert( ft::make_pair( 1988714904, 1988714904) );       // std::cout << " i = " << i++ << std::endl; // i = 362
map_int.insert( ft::make_pair( 1250372661, 1250372661) );       // std::cout << " i = " << i++ << std::endl; // i = 363
map_int.insert( ft::make_pair( 483689685, 483689685) );         // std::cout << " i = " << i++ << std::endl; // i = 364
map_int.insert( ft::make_pair( 1360613073, 1360613073) );       // std::cout << " i = " << i++ << std::endl; // i = 365
map_int.insert( ft::make_pair( 35756851, 35756851) );           // std::cout << " i = " << i++ << std::endl; // i = 366
map_int.insert( ft::make_pair( 746349250, 746349250) );         // std::cout << " i = " << i++ << std::endl; // i = 367
map_int.insert( ft::make_pair( 1122336503, 1122336503) );       // std::cout << " i = " << i++ << std::endl; // i = 368
map_int.insert( ft::make_pair( 659639006, 659639006) );         // std::cout << " i = " << i++ << std::endl; // i = 369
map_int.insert( ft::make_pair( 1385414639, 1385414639) );       // std::cout << " i = " << i++ << std::endl; // i = 370
map_int.insert( ft::make_pair( 577721120, 577721120) );         // std::cout << " i = " << i++ << std::endl; // i = 371
map_int.insert( ft::make_pair( 714880226, 714880226) );         // std::cout << " i = " << i++ << std::endl; // i = 372
map_int.insert( ft::make_pair( 1630387677, 1630387677) );       // std::cout << " i = " << i++ << std::endl; // i = 373
map_int.insert( ft::make_pair( 1467963981, 1467963981) );       // std::cout << " i = " << i++ << std::endl; // i = 374
map_int.insert( ft::make_pair( 1814887560, 1814887560) );       // std::cout << " i = " << i++ << std::endl; // i = 375
map_int.insert( ft::make_pair( 1290127955, 1290127955) );       // std::cout << " i = " << i++ << std::endl; // i = 376
map_int.insert( ft::make_pair( 1434433518, 1434433518) );       // std::cout << " i = " << i++ << std::endl; // i = 377
map_int.insert( ft::make_pair( 1821066342, 1821066342) );       // std::cout << " i = " << i++ << std::endl; // i = 378
map_int.insert( ft::make_pair( 550245196, 550245196) );         // std::cout << " i = " << i++ << std::endl; // i = 379
map_int.insert( ft::make_pair( 1104627321, 1104627321) );       // std::cout << " i = " << i++ << std::endl; // i = 380
map_int.insert( ft::make_pair( 1312994984, 1312994984) );       // std::cout << " i = " << i++ << std::endl; // i = 381
map_int.insert( ft::make_pair( 1763794427, 1763794427) );       // std::cout << " i = " << i++ << std::endl; // i = 382
map_int.insert( ft::make_pair( 1582152040, 1582152040) );       // std::cout << " i = " << i++ << std::endl; // i = 383
map_int.insert( ft::make_pair( 772970072, 772970072) );         // std::cout << " i = " << i++ << std::endl; // i = 384
map_int.insert( ft::make_pair( 51245830, 51245830) );           // std::cout << " i = " << i++ << std::endl; // i = 385
map_int.insert( ft::make_pair( 1046370347, 1046370347) );       // std::cout << " i = " << i++ << std::endl; // i = 386
map_int.insert( ft::make_pair( 1520982030, 1520982030) );       // std::cout << " i = " << i++ << std::endl; // i = 387
map_int.insert( ft::make_pair( 1089653714, 1089653714) );       // std::cout << " i = " << i++ << std::endl; // i = 388
map_int.insert( ft::make_pair( 168057522, 168057522) );         // std::cout << " i = " << i++ << std::endl; // i = 389
map_int.insert( ft::make_pair( 1038626924, 1038626924) );       // std::cout << " i = " << i++ << std::endl; // i = 390
map_int.insert( ft::make_pair( 93189435, 93189435) );           // std::cout << " i = " << i++ << std::endl; // i = 391
map_int.insert( ft::make_pair( 525829204, 525829204) );         // std::cout << " i = " << i++ << std::endl; // i = 392
map_int.insert( ft::make_pair( 1312630443, 1312630443) );       // std::cout << " i = " << i++ << std::endl; // i = 393
map_int.insert( ft::make_pair( 2064945486, 2064945486) );       // std::cout << " i = " << i++ << std::endl; // i = 394
map_int.insert( ft::make_pair( 356684278, 356684278) );         // std::cout << " i = " << i++ << std::endl; // i = 395
map_int.insert( ft::make_pair( 1626250262, 1626250262) );       // std::cout << " i = " << i++ << std::endl; // i = 396
map_int.insert( ft::make_pair( 14989683, 14989683) );           // std::cout << " i = " << i++ << std::endl; // i = 397
map_int.insert( ft::make_pair( 1581539848, 1581539848) );       // std::cout << " i = " << i++ << std::endl; // i = 398
map_int.insert( ft::make_pair( 1981208324, 1981208324) );       // std::cout << " i = " << i++ << std::endl; // i = 399
map_int.insert( ft::make_pair( 1691449122, 1691449122) );       // std::cout << " i = " << i++ << std::endl; // i = 400
map_int.insert( ft::make_pair( 217927335, 217927335) );         // std::cout << " i = " << i++ << std::endl; // i = 401
map_int.insert( ft::make_pair( 513937457, 513937457) );         // std::cout << " i = " << i++ << std::endl; // i = 402
map_int.insert( ft::make_pair( 204102747, 204102747) );         // std::cout << " i = " << i++ << std::endl; // i = 403
map_int.insert( ft::make_pair( 595311776, 595311776) );         // std::cout << " i = " << i++ << std::endl; // i = 404
map_int.insert( ft::make_pair( 2013725218, 2013725218) );       // std::cout << " i = " << i++ << std::endl; // i = 405
map_int.insert( ft::make_pair( 207621703, 207621703) );         // std::cout << " i = " << i++ << std::endl; // i = 406
map_int.insert( ft::make_pair( 1815209933, 1815209933) );       // std::cout << " i = " << i++ << std::endl; // i = 407
map_int.insert( ft::make_pair( 1487053959, 1487053959) );       // std::cout << " i = " << i++ << std::endl; // i = 408
map_int.insert( ft::make_pair( 932862806, 932862806) );         // std::cout << " i = " << i++ << std::endl; // i = 409
map_int.insert( ft::make_pair( 695748720, 695748720) );         // std::cout << " i = " << i++ << std::endl; // i = 410
map_int.insert( ft::make_pair( 279121308, 279121308) );         // std::cout << " i = " << i++ << std::endl; // i = 411
map_int.insert( ft::make_pair( 811742698, 811742698) );         // std::cout << " i = " << i++ << std::endl; // i = 412
map_int.insert( ft::make_pair( 1417076376, 1417076376) );       // std::cout << " i = " << i++ << std::endl; // i = 413
map_int.insert( ft::make_pair( 1891252715, 1891252715) );       // std::cout << " i = " << i++ << std::endl; // i = 414
map_int.insert( ft::make_pair( 452825171, 452825171) );         // std::cout << " i = " << i++ << std::endl; // i = 415
map_int.insert( ft::make_pair( 1135771559, 1135771559) );       // std::cout << " i = " << i++ << std::endl; // i = 416
map_int.insert( ft::make_pair( 2025554010, 2025554010) );       // std::cout << " i = " << i++ << std::endl; // i = 417
map_int.insert( ft::make_pair( 262178224, 262178224) );         // std::cout << " i = " << i++ << std::endl; // i = 418
map_int.insert( ft::make_pair( 1105816539, 1105816539) );       // std::cout << " i = " << i++ << std::endl; // i = 419
map_int.insert( ft::make_pair( 454333378, 454333378) );         // std::cout << " i = " << i++ << std::endl; // i = 420
map_int.insert( ft::make_pair( 343945053, 343945053) );         // std::cout << " i = " << i++ << std::endl; // i = 421
map_int.insert( ft::make_pair( 931489114, 931489114) );         // std::cout << " i = " << i++ << std::endl; // i = 422
map_int.insert( ft::make_pair( 1395405989, 1395405989) );       // std::cout << " i = " << i++ << std::endl; // i = 423
map_int.insert( ft::make_pair( 992028067, 992028067) );         // std::cout << " i = " << i++ << std::endl; // i = 424
map_int.insert( ft::make_pair( 1675575223, 1675575223) );       // std::cout << " i = " << i++ << std::endl; // i = 425
map_int.insert( ft::make_pair( 1470332231, 1470332231) );       // std::cout << " i = " << i++ << std::endl; // i = 426
map_int.insert( ft::make_pair( 1862292122, 1862292122) );       // std::cout << " i = " << i++ << std::endl; // i = 427
map_int.insert( ft::make_pair( 101323875, 101323875) );         // std::cout << " i = " << i++ << std::endl; // i = 428
map_int.insert( ft::make_pair( 380390179, 380390179) );         // std::cout << " i = " << i++ << std::endl; // i = 429
map_int.insert( ft::make_pair( 235202254, 235202254) );         // std::cout << " i = " << i++ << std::endl; // i = 430
map_int.insert( ft::make_pair( 1280311131, 1280311131) );       // std::cout << " i = " << i++ << std::endl; // i = 431
map_int.insert( ft::make_pair( 1503967857, 1503967857) );       // std::cout << " i = " << i++ << std::endl; // i = 432
map_int.insert( ft::make_pair( 873199181, 873199181) );         // std::cout << " i = " << i++ << std::endl; // i = 433
map_int.insert( ft::make_pair( 1240554603, 1240554603) );       // std::cout << " i = " << i++ << std::endl; // i = 434
map_int.insert( ft::make_pair( 476152433, 476152433) );         // std::cout << " i = " << i++ << std::endl; // i = 435
map_int.insert( ft::make_pair( 803590181, 803590181) );         // std::cout << " i = " << i++ << std::endl; // i = 436
map_int.insert( ft::make_pair( 209359415, 209359415) );         // std::cout << " i = " << i++ << std::endl; // i = 437
map_int.insert( ft::make_pair( 831768825, 831768825) );         // std::cout << " i = " << i++ << std::endl; // i = 438
map_int.insert( ft::make_pair( 2006138722, 2006138722) );       // std::cout << " i = " << i++ << std::endl; // i = 439
map_int.insert( ft::make_pair( 1785550551, 1785550551) );       // std::cout << " i = " << i++ << std::endl; // i = 440
map_int.insert( ft::make_pair( 1364090032, 1364090032) );       // std::cout << " i = " << i++ << std::endl; // i = 441
map_int.insert( ft::make_pair( 1341443181, 1341443181) );       // std::cout << " i = " << i++ << std::endl; // i = 442
map_int.insert( ft::make_pair( 1242990415, 1242990415) );       // std::cout << " i = " << i++ << std::endl; // i = 443
map_int.insert( ft::make_pair( 63299708, 63299708) );           // std::cout << " i = " << i++ << std::endl; // i = 444
map_int.insert( ft::make_pair( 1287859999, 1287859999) );       // std::cout << " i = " << i++ << std::endl; // i = 445
map_int.insert( ft::make_pair( 309112297, 309112297) );         // std::cout << " i = " << i++ << std::endl; // i = 446
map_int.insert( ft::make_pair( 1669475776, 1669475776) );       // std::cout << " i = " << i++ << std::endl; // i = 447
map_int.insert( ft::make_pair( 1579068977, 1579068977) );       // std::cout << " i = " << i++ << std::endl; // i = 448
map_int.insert( ft::make_pair( 1431742587, 1431742587) );       // std::cout << " i = " << i++ << std::endl; // i = 449
map_int.insert( ft::make_pair( 226723382, 226723382) );         // std::cout << " i = " << i++ << std::endl; // i = 450
map_int.insert( ft::make_pair( 219544266, 219544266) );         // std::cout << " i = " << i++ << std::endl; // i = 451
map_int.insert( ft::make_pair( 580508860, 580508860) );         // std::cout << " i = " << i++ << std::endl; // i = 452
map_int.insert( ft::make_pair( 617909211, 617909211) );         // std::cout << " i = " << i++ << std::endl; // i = 453
map_int.insert( ft::make_pair( 2033669086, 2033669086) );       // std::cout << " i = " << i++ << std::endl; // i = 454
map_int.insert( ft::make_pair( 1088590930, 1088590930) );       // std::cout << " i = " << i++ << std::endl; // i = 455
map_int.insert( ft::make_pair( 2010794583, 2010794583) );       // std::cout << " i = " << i++ << std::endl; // i = 456
map_int.insert( ft::make_pair( 632651476, 632651476) );         // std::cout << " i = " << i++ << std::endl; // i = 457
map_int.insert( ft::make_pair( 1384095820, 1384095820) );       // std::cout << " i = " << i++ << std::endl; // i = 458
map_int.insert( ft::make_pair( 500037525, 500037525) );         // std::cout << " i = " << i++ << std::endl; // i = 459
map_int.insert( ft::make_pair( 1351538839, 1351538839) );       // std::cout << " i = " << i++ << std::endl; // i = 460
map_int.insert( ft::make_pair( 1745897490, 1745897490) );       // std::cout << " i = " << i++ << std::endl; // i = 461
map_int.insert( ft::make_pair( 61101360, 61101360) );           // std::cout << " i = " << i++ << std::endl; // i = 462
map_int.insert( ft::make_pair( 1326247643, 1326247643) );       // std::cout << " i = " << i++ << std::endl; // i = 463
map_int.insert( ft::make_pair( 1663080928, 1663080928) );       // std::cout << " i = " << i++ << std::endl; // i = 464
map_int.insert( ft::make_pair( 164826621, 164826621) );         // std::cout << " i = " << i++ << std::endl; // i = 465
map_int.insert( ft::make_pair( 370917955, 370917955) );         // std::cout << " i = " << i++ << std::endl; // i = 466
map_int.insert( ft::make_pair( 772634225, 772634225) );         // std::cout << " i = " << i++ << std::endl; // i = 467
map_int.insert( ft::make_pair( 813274570, 813274570) );         // std::cout << " i = " << i++ << std::endl; // i = 468
map_int.insert( ft::make_pair( 216220853, 216220853) );         // std::cout << " i = " << i++ << std::endl; // i = 469
map_int.insert( ft::make_pair( 1867107722, 1867107722) );       // std::cout << " i = " << i++ << std::endl; // i = 470
map_int.insert( ft::make_pair( 223712350, 223712350) );         // std::cout << " i = " << i++ << std::endl; // i = 471
map_int.insert( ft::make_pair( 1610009097, 1610009097) );       // std::cout << " i = " << i++ << std::endl; // i = 472
map_int.insert( ft::make_pair( 787689126, 787689126) );         // std::cout << " i = " << i++ << std::endl; // i = 473
map_int.insert( ft::make_pair( 584522071, 584522071) );         // std::cout << " i = " << i++ << std::endl; // i = 474
map_int.insert( ft::make_pair( 146533149, 146533149) );         // std::cout << " i = " << i++ << std::endl; // i = 475
map_int.insert( ft::make_pair( 928140528, 928140528) );         // std::cout << " i = " << i++ << std::endl; // i = 476
map_int.insert( ft::make_pair( 1449228398, 1449228398) );       // std::cout << " i = " << i++ << std::endl; // i = 477
map_int.insert( ft::make_pair( 1012836610, 1012836610) );       // std::cout << " i = " << i++ << std::endl; // i = 478
map_int.insert( ft::make_pair( 481928577, 481928577) );         // std::cout << " i = " << i++ << std::endl; // i = 479
map_int.insert( ft::make_pair( 1238498976, 1238498976) );       // std::cout << " i = " << i++ << std::endl; // i = 480
map_int.insert( ft::make_pair( 270754552, 270754552) );         // std::cout << " i = " << i++ << std::endl; // i = 481
map_int.insert( ft::make_pair( 1031126087, 1031126087) );       // std::cout << " i = " << i++ << std::endl; // i = 482
map_int.insert( ft::make_pair( 413360099, 413360099) );         // std::cout << " i = " << i++ << std::endl; // i = 483
map_int.insert( ft::make_pair( 286448566, 286448566) );         // std::cout << " i = " << i++ << std::endl; // i = 484
map_int.insert( ft::make_pair( 396377017, 396377017) );         // std::cout << " i = " << i++ << std::endl; // i = 485
map_int.insert( ft::make_pair( 1934392735, 1934392735) );       // std::cout << " i = " << i++ << std::endl; // i = 486
map_int.insert( ft::make_pair( 1736491298, 1736491298) );       // std::cout << " i = " << i++ << std::endl; // i = 487
map_int.insert( ft::make_pair( 1476453195, 1476453195) );       // std::cout << " i = " << i++ << std::endl; // i = 488
map_int.insert( ft::make_pair( 96055805, 96055805) );           // std::cout << " i = " << i++ << std::endl; // i = 489
map_int.insert( ft::make_pair( 1664423428, 1664423428) );       // std::cout << " i = " << i++ << std::endl; // i = 490
map_int.insert( ft::make_pair( 1849552528, 1849552528) );       // std::cout << " i = " << i++ << std::endl; // i = 491
map_int.insert( ft::make_pair( 2135019593, 2135019593) );       // std::cout << " i = " << i++ << std::endl; // i = 492
map_int.insert( ft::make_pair( 1434322197, 1434322197) );       // std::cout << " i = " << i++ << std::endl; // i = 493
map_int.insert( ft::make_pair( 1779289672, 1779289672) );       // std::cout << " i = " << i++ << std::endl; // i = 494
map_int.insert( ft::make_pair( 1528806445, 1528806445) );       // std::cout << " i = " << i++ << std::endl; // i = 495
map_int.insert( ft::make_pair( 415522325, 415522325) );         // std::cout << " i = " << i++ << std::endl; // i = 496
map_int.insert( ft::make_pair( 332238283, 332238283) );         // std::cout << " i = " << i++ << std::endl; // i = 497
map_int.insert( ft::make_pair( 695466127, 695466127) );         // std::cout << " i = " << i++ << std::endl; // i = 498
map_int.insert( ft::make_pair( 1143565421, 1143565421) );       // std::cout << " i = " << i++ << std::endl; // i = 499
map_int.insert( ft::make_pair( 1375179334, 1375179334) );       // std::cout << " i = " << i++ << std::endl; // i = 500
map_int.insert( ft::make_pair( 987987334, 987987334) );         // std::cout << " i = " << i++ << std::endl; // i = 501
map_int.insert( ft::make_pair( 12548159, 12548159) );           // std::cout << " i = " << i++ << std::endl; // i = 502
map_int.insert( ft::make_pair( 411522957, 411522957) );         // std::cout << " i = " << i++ << std::endl; // i = 503
map_int.insert( ft::make_pair( 953691761, 953691761) );         // std::cout << " i = " << i++ << std::endl; // i = 504
map_int.insert( ft::make_pair( 1402492972, 1402492972) );       // std::cout << " i = " << i++ << std::endl; // i = 505
map_int.insert( ft::make_pair( 750167716, 750167716) );         // std::cout << " i = " << i++ << std::endl; // i = 506
map_int.insert( ft::make_pair( 915711850, 915711850) );         // std::cout << " i = " << i++ << std::endl; // i = 507
map_int.insert( ft::make_pair( 108375482, 108375482) );         // std::cout << " i = " << i++ << std::endl; // i = 508
map_int.insert( ft::make_pair( 1738076217, 1738076217) );       // std::cout << " i = " << i++ << std::endl; // i = 509
map_int.insert( ft::make_pair( 2118801173, 2118801173) );       // std::cout << " i = " << i++ << std::endl; // i = 510
map_int.insert( ft::make_pair( 610486506, 610486506) );         // std::cout << " i = " << i++ << std::endl; // i = 511
map_int.insert( ft::make_pair( 771476364, 771476364) );         // std::cout << " i = " << i++ << std::endl; // i = 512
map_int.insert( ft::make_pair( 1833488263, 1833488263) );       // std::cout << " i = " << i++ << std::endl; // i = 513
map_int.insert( ft::make_pair( 1688323172, 1688323172) );       // std::cout << " i = " << i++ << std::endl; // i = 514
map_int.insert( ft::make_pair( 301373537, 301373537) );         // std::cout << " i = " << i++ << std::endl; // i = 515
map_int.insert( ft::make_pair( 222028828, 222028828) );         // std::cout << " i = " << i++ << std::endl; // i = 516
map_int.insert( ft::make_pair( 2078107280, 2078107280) );       // std::cout << " i = " << i++ << std::endl; // i = 517
map_int.insert( ft::make_pair( 1866355856, 1866355856) );       // std::cout << " i = " << i++ << std::endl; // i = 518
map_int.insert( ft::make_pair( 1723578341, 1723578341) );       // std::cout << " i = " << i++ << std::endl; // i = 519
map_int.insert( ft::make_pair( 849725352, 849725352) );         // std::cout << " i = " << i++ << std::endl; // i = 520
map_int.insert( ft::make_pair( 1143195511, 1143195511) );       // std::cout << " i = " << i++ << std::endl; // i = 521
map_int.insert( ft::make_pair( 2083149517, 2083149517) );       // std::cout << " i = " << i++ << std::endl; // i = 522
map_int.insert( ft::make_pair( 190113083, 190113083) );         // std::cout << " i = " << i++ << std::endl; // i = 523
map_int.insert( ft::make_pair( 113974112, 113974112) );         // std::cout << " i = " << i++ << std::endl; // i = 524
map_int.insert( ft::make_pair( 1931706506, 1931706506) );       // std::cout << " i = " << i++ << std::endl; // i = 525
map_int.insert( ft::make_pair( 900104667, 900104667) );         // std::cout << " i = " << i++ << std::endl; // i = 526
map_int.insert( ft::make_pair( 472131489, 472131489) );         // std::cout << " i = " << i++ << std::endl; // i = 527
map_int.insert( ft::make_pair( 1337434154, 1337434154) );       // std::cout << " i = " << i++ << std::endl; // i = 528
map_int.insert( ft::make_pair( 991039875, 991039875) );         // std::cout << " i = " << i++ << std::endl; // i = 529
map_int.insert( ft::make_pair( 987706141, 987706141) );         // std::cout << " i = " << i++ << std::endl; // i = 530
map_int.insert( ft::make_pair( 1794292538, 1794292538) );       // std::cout << " i = " << i++ << std::endl; // i = 531
map_int.insert( ft::make_pair( 434290636, 434290636) );         // std::cout << " i = " << i++ << std::endl; // i = 532
map_int.insert( ft::make_pair( 1444311956, 1444311956) );       // std::cout << " i = " << i++ << std::endl; // i = 533
map_int.insert( ft::make_pair( 2067062760, 2067062760) );       // std::cout << " i = " << i++ << std::endl; // i = 534
map_int.insert( ft::make_pair( 825726814, 825726814) );         // std::cout << " i = " << i++ << std::endl; // i = 535
map_int.insert( ft::make_pair( 1998994314, 1998994314) );       // std::cout << " i = " << i++ << std::endl; // i = 536
map_int.insert( ft::make_pair( 221713886, 221713886) );         // std::cout << " i = " << i++ << std::endl; // i = 537
map_int.insert( ft::make_pair( 1880346039, 1880346039) );       // std::cout << " i = " << i++ << std::endl; // i = 538
map_int.insert( ft::make_pair( 1978701535, 1978701535) );       // std::cout << " i = " << i++ << std::endl; // i = 539
map_int.insert( ft::make_pair( 192532621, 192532621) );         // std::cout << " i = " << i++ << std::endl; // i = 540
map_int.insert( ft::make_pair( 2079611790, 2079611790) );       // std::cout << " i = " << i++ << std::endl; // i = 541
map_int.insert( ft::make_pair( 10150109, 10150109) );           // std::cout << " i = " << i++ << std::endl; // i = 542
map_int.insert( ft::make_pair( 616734673, 616734673) );         // std::cout << " i = " << i++ << std::endl; // i = 543
map_int.insert( ft::make_pair( 562395735, 562395735) );         // std::cout << " i = " << i++ << std::endl; // i = 544
map_int.insert( ft::make_pair( 78374295, 78374295) );           // std::cout << " i = " << i++ << std::endl; // i = 545
map_int.insert( ft::make_pair( 752704313, 752704313) );         // std::cout << " i = " << i++ << std::endl; // i = 546
map_int.insert( ft::make_pair( 612353198, 612353198) );         // std::cout << " i = " << i++ << std::endl; // i = 547
map_int.insert( ft::make_pair( 1450099355, 1450099355) );       // std::cout << " i = " << i++ << std::endl; // i = 548
map_int.insert( ft::make_pair( 1340157793, 1340157793) );       // std::cout << " i = " << i++ << std::endl; // i = 549
map_int.insert( ft::make_pair( 929588156, 929588156) );         // std::cout << " i = " << i++ << std::endl; // i = 550
map_int.insert( ft::make_pair( 2138982933, 2138982933) );       // std::cout << " i = " << i++ << std::endl; // i = 551
map_int.insert( ft::make_pair( 1987323286, 1987323286) );       // std::cout << " i = " << i++ << std::endl; // i = 552
map_int.insert( ft::make_pair( 568275358, 568275358) );         // std::cout << " i = " << i++ << std::endl; // i = 553
map_int.insert( ft::make_pair( 625040140, 625040140) );         // std::cout << " i = " << i++ << std::endl; // i = 554
map_int.insert( ft::make_pair( 1567022181, 1567022181) );       // std::cout << " i = " << i++ << std::endl; // i = 555

        std::cout << " fill: end" << std::endl;

}

int nb_setw = 10;
std::string nb_str_space(nb_setw, ' ');

template <typename T>
void print_int_key_node_fluid(ft::Node<ft::pair<const int, T> > *node) {
    if ( node->_is_empty == false ) {
        if ( node->color == 1 ) {
            std::cout << "\033[30;41m" << std::setw(nb_setw) << node->data.first << "\033[0m";
        } else {
            std::cout << "\033[37;40m" << std::setw(nb_setw) << node->data.first << "\033[0m";
        }
    } else {
		if ( nb_setw > 3 ) {
			std::cout << "\033[37;40m";
			for ( int i = 0; i < (nb_setw - 3)/2; ++i) {
        		std::cout << nb_str_space[i] ;
			}
        	std::cout << "NIL" ;
			for ( int i = (nb_setw - 3)/2 + 3; i <= nb_setw; ++i) {
        		std::cout << nb_str_space[i] ;
			}
        	std::cout << "\033[0m" ;
		} else {
        	std::cout << "\033[37;40m" " NIL " "\033[0m" ;
		}
    }
}

template <typename T>
void tree_picture_fluid(ft::map<int, T> &my_tree) {
    if ( my_tree.empty() ) {
        std::cout << "Tree is empty. " << std::endl;
        return ;
    }
	std::string str_start(nb_setw/2, ' ');
	std::string str____(nb_setw + 2, '_');

    // 80
    std::cout << str_start << nb_str_space << nb_str_space << nb_str_space
    		  << nb_str_space << nb_str_space << nb_str_space << nb_str_space
			  << "              " ;
    print_int_key_node_fluid( my_tree.root().base() );
    std::cout << std::endl;

    std::cout << str_start << nb_str_space << nb_str_space << nb_str_space << nb_str_space << "      " 
	          << str____ << str____ << str____ << "_/" << nb_str_space << "\\_"
			  << str____ << str____ << str____ << std::endl;
    // 10 120 // 2h
    std::cout << str_start << nb_str_space << nb_str_space << nb_str_space << "      ";
    print_int_key_node_fluid( my_tree.root().base()->left ); // 2h-1w pos
    std::cout << nb_str_space << nb_str_space << nb_str_space << nb_str_space;
    std::cout << nb_str_space << nb_str_space << nb_str_space << "                ";

    print_int_key_node_fluid( my_tree.root().base()->right ); // 2h-2w pos
    if ( my_tree.root().base()->left->_is_empty == false && my_tree.root().base()->right->_is_empty == false) {
        std::cout << std::endl << str_start << nb_str_space << "  "<< nb_str_space << str____ << "_/" << nb_str_space << "\\_" << str____  
				  << nb_str_space << nb_str_space << nb_str_space << nb_str_space << "        " << nb_str_space 
				  << str____ << "_/" << nb_str_space << "\\_" << str____ << std::endl;  // 3h-1,2,3,4w pos
    } else if ( my_tree.root().base()->left->_is_empty == false && my_tree.root().base()->right->_is_empty == true ) {
        std::cout << std::endl << str_start << nb_str_space << "  "<< nb_str_space << str____ << "_/" << nb_str_space << "\\_" << str____ << std::endl;
    } else if (my_tree.root().base()->left->_is_empty == true && my_tree.root().base()->right->_is_empty == false) {
        std::cout << std::endl << str_start << nb_str_space << "  "<< nb_str_space << nb_str_space << "    " << nb_str_space << "    " << nb_str_space  
				  << nb_str_space << nb_str_space << nb_str_space << nb_str_space << "        " << nb_str_space 
				  << str____ << "_/" << nb_str_space << "\\_" << str____ << std::endl;  // 3h-1,2,3,4w pos
    } else {
        std::cout << std::endl;
        return ;
    }
    // 0 40 100 140 // 3h
    if ( my_tree.root().base()->left->_is_empty == false ) {
        std::cout << str_start << nb_str_space << " _";
        print_int_key_node_fluid( my_tree.root().base()->left->left ); // 3h-1w pos
        std::cout << "_" << "      " << nb_str_space << nb_str_space << nb_str_space << "_";
        print_int_key_node_fluid( my_tree.root().base()->left->right ); // 3h-2w pos
        std::cout << "_" << "      " << nb_str_space << nb_str_space << nb_str_space;
    } else {
        std::cout << str_start << nb_str_space << "   "
                  << nb_str_space // 3h-1w pos
                  << "          " << nb_str_space << nb_str_space << nb_str_space << " "
                  << nb_str_space // 3h-2w pos
                  << " " << "      " << nb_str_space << nb_str_space << nb_str_space;
    }
    if ( my_tree.root().base()->right->_is_empty == false ) {
        std::cout << "_";
        print_int_key_node_fluid( my_tree.root().base()->right->left ); // 3h-3w pos
        std::cout << "_" << "      " << nb_str_space << nb_str_space << nb_str_space << "_";
        print_int_key_node_fluid( my_tree.root().base()->right->right ); // 3h-4w pos
        std::cout << "_";
    }
    
    std::cout << std::endl;
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false ) {
        std::cout << str_start << nb_str_space << "/" << nb_str_space << "  \\    "; // 4h-1,2w pos
    } else {
        std::cout << str_start << nb_str_space << nb_str_space << "        "; // 4h-1,2w pos
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false ) {
        std::cout << nb_str_space << nb_str_space << nb_str_space << "/" << nb_str_space << "  \\    "; // 4h-3,4w pos
    } else {
        std::cout << nb_str_space << nb_str_space << nb_str_space << nb_str_space << "        "; // 4h-3,4w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false ) {
        std::cout << nb_str_space << nb_str_space << nb_str_space << "/" << nb_str_space << "  \\    "; // 4h-5,6w pos
    } else {
        std::cout << nb_str_space << nb_str_space << nb_str_space << nb_str_space << "        "; // 4h-5,6w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false ) {
        std::cout << nb_str_space << nb_str_space << nb_str_space << "/" << nb_str_space << "  \\    "; // 4h-7,8w pos
    }
    std::cout << std::endl;
    // -10 NIL 20 NIL 90 110 130 150
    if ( ( my_tree.root().base()->left->_is_empty && 
           my_tree.root().base()->right->_is_empty ) ||
         ( my_tree.root().base()->left->_is_empty == false &&
           my_tree.root().base()->left->left->_is_empty && 
           my_tree.root().base()->left->right->_is_empty && 
           my_tree.root().base()->right->_is_empty ) ||
         ( my_tree.root().base()->right->_is_empty == false &&
           my_tree.root().base()->right->left->_is_empty && 
           my_tree.root().base()->right->right->_is_empty && 
           my_tree.root().base()->left->_is_empty )
       ) {
           return ;
    }

    if ( my_tree.root().base()->left->_is_empty ) {
        std::cout << str_start << nb_str_space << nb_str_space << "        ";
    } else {
        if (my_tree.root().base()->left->left->_is_empty == false) {
            std::cout << str_start;
            print_int_key_node_fluid( my_tree.root().base()->left->left->left ); // 4h-1w pos
            std::cout << nb_str_space << "    ";
            print_int_key_node_fluid( my_tree.root().base()->left->left->right ); // 4h-2w pos
            std::cout << nb_str_space << "    ";
        } else {
            std::cout << str_start << nb_str_space << nb_str_space << "    " << nb_str_space << nb_str_space << "    ";
        }
        if (my_tree.root().base()->left->right->_is_empty == false) {
            print_int_key_node_fluid( my_tree.root().base()->left->right->left ); // 4h-3w pos
            std::cout << nb_str_space << "    ";
            print_int_key_node_fluid( my_tree.root().base()->left->right->right ); // 4h-4w pos
            std::cout << nb_str_space << "    ";
        } else {
            std::cout << nb_str_space << nb_str_space << "    " << nb_str_space << nb_str_space << "    ";
        }
    }
    if ( my_tree.root().base()->right->_is_empty == false ) {
        if (my_tree.root().base()->right->left->_is_empty == false) {
            print_int_key_node_fluid( my_tree.root().base()->right->left->left ); // 4h-5w pos
            std::cout << nb_str_space << "    ";
            print_int_key_node_fluid( my_tree.root().base()->right->left->right ); // 4h-6w pos
            std::cout << nb_str_space << "    ";
        } else {
            std::cout << nb_str_space << nb_str_space << "    " << nb_str_space << nb_str_space << "    ";
        }
        if (my_tree.root().base()->right->right->_is_empty == false) {
            print_int_key_node_fluid( my_tree.root().base()->right->right->left ); // 4h-7w pos
            std::cout << nb_str_space << "    ";
            print_int_key_node_fluid( my_tree.root().base()->right->right->right ); // 4h-8w pos
        }
    }
    std::cout << std::endl;
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->left->_is_empty == false ) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-1,2w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-1w pos

    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->right->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-3,4w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-3,4w pos
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->left->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space; // 5h-5,6w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-5,6w pos
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->right->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space; // 5h-7,8w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-7,8w pos
    }


    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->left->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-9,10w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-9,10w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->right->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-11,12w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-11,12w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->left->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-13,14w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-13,14w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->right->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-15,16w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-15,16w pos
    }

    std::cout << std::endl;
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->left->_is_empty == false) {
        print_int_key_node_fluid( my_tree.root().base()->left->left->left->left ); // 5h-1w pos
        std::cout << "  " ;
        print_int_key_node_fluid( my_tree.root().base()->left->left->left->right ); // 5h-2w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->right->_is_empty == false) {
        print_int_key_node_fluid( my_tree.root().base()->left->left->right->left ); // 5h-3w pos
        std::cout << "  " ;
        print_int_key_node_fluid( my_tree.root().base()->left->left->right->right ); // 5h-4w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->left->_is_empty == false) {
        print_int_key_node_fluid( my_tree.root().base()->left->right->left->left ); // 5h-5w pos
        std::cout << "  " ;
        print_int_key_node_fluid( my_tree.root().base()->left->right->left->right ); // 5h-6w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->right->_is_empty == false) {
        print_int_key_node_fluid( my_tree.root().base()->left->right->right->left ); // 5h-7w pos
        std::cout << "  " ;
        print_int_key_node_fluid( my_tree.root().base()->left->right->right->right ); // 5h-8w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->left->_is_empty == false) {
        print_int_key_node_fluid( my_tree.root().base()->right->left->left->left ); // 5h-9w pos
        std::cout << "  " ;
        print_int_key_node_fluid( my_tree.root().base()->right->left->left->right ); // 5h-10w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->right->_is_empty == false) {
        print_int_key_node_fluid( my_tree.root().base()->right->left->right->left ); // 5h-11w pos
        std::cout << "  " ;
        print_int_key_node_fluid( my_tree.root().base()->right->left->right->right ); // 5h-12w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->left->_is_empty == false) {
        print_int_key_node_fluid( my_tree.root().base()->right->right->left->left ); // 5h-13w pos
        std::cout << "  " ;
        print_int_key_node_fluid( my_tree.root().base()->right->right->left->right ); // 5h-14w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->right->_is_empty == false) {
        print_int_key_node_fluid( my_tree.root().base()->right->right->right->left ); // 5h-15w pos
        std::cout << "  " ;
        print_int_key_node_fluid( my_tree.root().base()->right->right->right->right ); // 5h-16w pos
        std::cout << "  " ;
    }
    std::cout << std::endl;
    std::cout << "\n\033[36m" << " only for 5 lvls " << "\033[0m"  << std::endl;

}

#endif
