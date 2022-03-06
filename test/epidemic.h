//
// Created by Phoenix Wang on 2022/1/28.
//
// epidemic.h
// data from https://voice.baidu.com/act/newpneumonia/newpneumonia/?from=osari_aladin_banner

#include <vector>

#ifndef OPERATORS_EPIDEMIC_H
#define OPERATORS_EPIDEMIC_H

std::vector<std::string> epidemic_schema = {"地区", "新增", "累计", "治愈", "死亡"};
std::vector<std::vector<std::string>> row6 = {
        {"美国", "490495", "74176403", "45421318", "898680"},
        {"印度", "285914", "40371500", "37677328", "491729"},
        {"巴西", "199126", "24553950", "22036168", "624507"},
        {"法国", "501635", "17730556", "11053491", "129747"},
        {"英国", "94031", "16149319", "12781312", "154702"},
        {"俄罗斯", "74692", "11404617", "10129691", "328770"}
};

std::vector<std::vector<std::string>> row64 = {
        {"美国", "490495", "74176403", "45421318", "898680"},
        {"印度", "285914", "40371500", "37677328", "491729"},
        {"巴西", "199126", "24553950", "22036168", "624507"},
        {"法国", "501635", "17730556", "11053491", "129747"},
        {"英国", "94031", "16149319", "12781312", "154702"},
        {"俄罗斯", "74692", "11404617", "10129691", "328770"},
        {"土耳其", "76341", "11167927", "10484202", "86487"},
        {"意大利", "211277", "10383561", "7522210", "144770"},
        {"西班牙", "114877", "9529320", "5732941", "92591"},
        {"德国", "162787", "9145274", "7443300", "117883"},
        {"阿根廷", "100863", "8130023", "7162581", "120019"},
        {"伊朗", "11851", "6279410", "6088367", "132303"},
        {"哥伦比亚", "19512", "5798799", "5545155", "133019"},
        {"墨西哥", "44902", "4779296", "3853156", "304308"},
        {"波兰", "53416", "4695435", "3880924", "104636"},
        {"印度尼西亚", "7010", "4309270", "4129305", "144261"},
        {"荷兰", "58616", "4067075", "3055203", "21239"},
        {"乌克兰", "24321", "3946202", "3601952", "99738"},
        {"南非", "3197", "3590399", "3429498", "94491"},
        {"菲律宾", "15647", "3493447", "3213190", "53736"},
        {"秘鲁", "44496", "3070357", "1720665", "204769"},
        {"加拿大", "13899", "2979643", "2695771", "33192"},
        {"比利时", "47493", "2939439", "2021761", "28902"},
        {"捷克", "39716", "2888827", "2557250", "37114"},
        {"马来西亚", "4066", "2844969", "2766254", "31930"},
        {"以色列", "0", "2599456", "1865189", "8513"},
        {"泰国", "7587", "2407022", "2302164", "22101"},
        {"澳大利亚", "57161", "2390397", "1978446", "3389"},
        {"葡萄牙", "57657", "2377818", "1842153", "19703"},
        {"日本", "71604", "2359254", "1864355", "18604"},
        {"越南", "15954", "2203208", "1945611", "37291"},
        {"伊拉克", "8107", "2175793", "2087357", "24319"},
        {"罗马尼亚", "34255", "2083151", "1851867", "59726"},
        {"瑞士", "79319", "2037794", "1248263", "12751"},
        {"智利", "18736", "2020082", "1761486", "39547"},
        {"瑞典", "50495", "1973485", "1278921", "15734"},
        {"希腊", "0", "1848223", "1609789", "22970"},
        {"孟加拉国", "15527", "1731524", "1560006", "28273"},
        {"奥地利", "34011", "1727661", "1445628", "14042"},
        {"塞尔维亚", "19063", "1598910", "1329306", "13377"},
        {"匈牙利", "20174", "1490489", "1233499", "41151"},
        {"丹麦", "43719", "1468964", "996353", "3656"},
        {"巴基斯坦", "5196", "1393887", "1272871", "29162"},
        {"哈萨克斯坦", "11862", "1192211", "1021215", "13177"},
        {"约旦", "0", "1177165", "1097176", "13124"},
        {"爱尔兰", "4006", "1159271", "716325", "6136"},
        {"摩洛哥", "6362", "1114527", "1042269", "15237"},
        {"格鲁吉亚", "17530", "1110168", "981531", "14840"},
        {"古巴", "2764", "1031170", "1006319", "8376"},
        {"斯洛伐克", "13837", "957633", "854786", "17755"},
        {"尼泊尔", "5571", "939267", "837004", "11687"},
        {"保加利亚", "12399", "913592", "658492", "32939"},
        {"克罗地亚", "11812", "899174", "819581", "13566"},
        {"黎巴嫩", "7250", "882783", "682977", "9528"},
        {"突尼斯", "2834", "866445", "731135", "26051"},
        {"玻利维亚", "7649", "835170", "665789", "20774"},
        {"阿拉伯联合酋长国", "2369", "833201", "771624", "2228"},
        {"韩国", "13004", "777497", "610740", "6654"},
        {"白俄罗斯", "1897", "734078", "725935", "5992"},
        {"厄瓜多尔", "0", "691898", "443880", "34362"},
        {"挪威", "24429", "690244", "88952", "1439"},
        {"危地马拉", "3070", "677214", "625147", "16294"},
        {"巴拿马", "0", "669860", "580367", "7645"},
        {"哥斯达黎加", "5859", "668209", "572102", "7505"}
};

std::vector<std::string> schema0 = {"地区", "新增"};
std::vector<std::vector<std::string>> row60 = {
        {"美国", "490495"},
        {"印度", "285914"},
        {"巴西", "199126"},
        {"法国", "501635"},
        {"英国", "94031"},
        {"俄罗斯", "74692"}
};

std::vector<std::string> schema1 = {"地区", "新增", "累计"};
std::vector<std::vector<std::string>> row61 = {
        {"美国", "490495", "74176403"},
        {"印度", "285914", "40371500"},
        {"巴西", "199126", "24553950"},
        {"法国", "501635", "17730556"},
        {"英国", "94031", "16149319"},
        {"俄罗斯", "74692", "11404617"}
};

std::vector<std::string> schema2 = {"累计", "治愈", "死亡"};
std::vector<std::vector<std::string>> row62 = {
        {"74176403", "45421318", "898680"},
        {"40371500", "37677328", "491729"},
        {"24553950", "22036168", "624507"},
        {"17730556", "11053491", "129747"},
        {"16149319", "12781312", "154702"},
        {"11404617", "10129691", "328770"}
};

std::vector<std::string> r6 = {"土耳其", "76341", "11167927", "10484202", "86487"};
std::vector<std::vector<std::string>> epidemic =
        {{"美国", "490495", "74176403", "45421318", "898680"},
         {"印度", "285914", "40371500", "37677328", "491729"},
         {"巴西", "199126", "24553950", "22036168", "624507"},
         {"法国", "501635", "17730556", "11053491", "129747"},
         {"英国", "94031", "16149319", "12781312", "154702"},
         {"俄罗斯", "74692", "11404617", "10129691", "328770"},
         {"土耳其", "76341", "11167927", "10484202", "86487"},
         {"意大利", "211277", "10383561", "7522210", "144770"},
         {"西班牙", "114877", "9529320", "5732941", "92591"},
         {"德国", "162787", "9145274", "7443300", "117883"},
         {"阿根廷", "100863", "8130023", "7162581", "120019"},
         {"伊朗", "11851", "6279410", "6088367", "132303"},
         {"哥伦比亚", "19512", "5798799", "5545155", "133019"},
         {"墨西哥", "44902", "4779296", "3853156", "304308"},
         {"波兰", "53416", "4695435", "3880924", "104636"},
         {"印度尼西亚", "7010", "4309270", "4129305", "144261"},
         {"荷兰", "58616", "4067075", "3055203", "21239"},
         {"乌克兰", "24321", "3946202", "3601952", "99738"},
         {"南非", "3197", "3590399", "3429498", "94491"},
         {"菲律宾", "15647", "3493447", "3213190", "53736"},
         {"秘鲁", "44496", "3070357", "1720665", "204769"},
         {"加拿大", "13899", "2979643", "2695771", "33192"},
         {"比利时", "47493", "2939439", "2021761", "28902"},
         {"捷克", "39716", "2888827", "2557250", "37114"},
         {"马来西亚", "4066", "2844969", "2766254", "31930"},
         {"以色列", "0", "2599456", "1865189", "8513"},
         {"泰国", "7587", "2407022", "2302164", "22101"},
         {"澳大利亚", "57161", "2390397", "1978446", "3389"},
         {"葡萄牙", "57657", "2377818", "1842153", "19703"},
         {"日本", "71604", "2359254", "1864355", "18604"},
         {"越南", "15954", "2203208", "1945611", "37291"},
         {"伊拉克", "8107", "2175793", "2087357", "24319"},
         {"罗马尼亚", "34255", "2083151", "1851867", "59726"},
         {"瑞士", "79319", "2037794", "1248263", "12751"},
         {"智利", "18736", "2020082", "1761486", "39547"},
         {"瑞典", "50495", "1973485", "1278921", "15734"},
         {"希腊", "0", "1848223", "1609789", "22970"},
         {"孟加拉国", "15527", "1731524", "1560006", "28273"},
         {"奥地利", "34011", "1727661", "1445628", "14042"},
         {"塞尔维亚", "19063", "1598910", "1329306", "13377"},
         {"匈牙利", "20174", "1490489", "1233499", "41151"},
         {"丹麦", "43719", "1468964", "996353", "3656"},
         {"巴基斯坦", "5196", "1393887", "1272871", "29162"},
         {"哈萨克斯坦", "11862", "1192211", "1021215", "13177"},
         {"约旦", "0", "1177165", "1097176", "13124"},
         {"爱尔兰", "4006", "1159271", "716325", "6136"},
         {"摩洛哥", "6362", "1114527", "1042269", "15237"},
         {"格鲁吉亚", "17530", "1110168", "981531", "14840"},
         {"古巴", "2764", "1031170", "1006319", "8376"},
         {"斯洛伐克", "13837", "957633", "854786", "17755"},
         {"尼泊尔", "5571", "939267", "837004", "11687"},
         {"保加利亚", "12399", "913592", "658492", "32939"},
         {"克罗地亚", "11812", "899174", "819581", "13566"},
         {"黎巴嫩", "7250", "882783", "682977", "9528"},
         {"突尼斯", "2834", "866445", "731135", "26051"},
         {"玻利维亚", "7649", "835170", "665789", "20774"},
         {"阿拉伯联合酋长国", "2369", "833201", "771624", "2228"},
         {"韩国", "13004", "777497", "610740", "6654"},
         {"白俄罗斯", "1897", "734078", "725935", "5992"},
         {"厄瓜多尔", "0", "691898", "443880", "34362"},
         {"挪威", "24429", "690244", "88952", "1439"},
         {"危地马拉", "3070", "677214", "625147", "16294"},
         {"巴拿马", "0", "669860", "580367", "7645"},
         {"哥斯达黎加", "5859", "668209", "572102", "7505"},
         {"沙特阿拉伯", "4526", "666259", "617114", "8927"},
         {"斯洛文尼亚", "17553", "642342", "500153", "5810"},
         {"阿塞拜疆", "3192", "640148", "619050", "8650"},
         {"立陶宛", "10301", "639527", "541642", "7815"},
         {"乌拉圭", "10745", "621453", "539075", "6368"},
         {"斯里兰卡", "891", "604581", "576781", "15346"},
         {"巴拉圭", "5864", "554182", "476125", "17112"},
         {"多米尼加", "2272", "547091", "523189", "4293"},
         {"缅甸", "0", "534503", "512581", "19310"},
         {"科威特", "5742", "514826", "464853", "2489"},
         {"委内瑞拉", "1736", "475135", "452613", "5419"},
         {"芬兰", "8039", "470665", "46000", "1919"},
         {"巴勒斯坦", "0", "466697", "439810", "4805"},
         {"埃塞俄比亚", "533", "463465", "394030", "7292"},
         {"蒙古国", "3080", "435681", "313256", "2102"},
         {"摩尔多瓦", "5138", "423568", "374873", "10587"},
         {"埃及", "1809", "415468", "349427", "22460"},
         {"利比亚", "2245", "413066", "389620", "5967"},
         {"洪都拉斯", "763", "391874", "127038", "10504"},
         {"拉脱维亚", "9143", "363821", "288705", "4846"},
         {"亚美尼亚", "1931", "358218", "334960", "8035"},
         {"巴林", "4360", "343400", "311418", "1400"},
         {"波黑", "2601", "339281", "192218", "14185"},
         {"卡塔尔", "2551", "330848", "297167", "638"},
         {"阿曼", "2162", "330767", "308825", "4134"},
         {"新加坡", "10828", "327602", "308480", "850"},
         {"肯尼亚", "367", "320766", "292587", "5565"},
         {"爱沙尼亚", "5843", "313685", "250826", "2023"},
         {"赞比亚", "697", "304002", "294802", "3907"},
         {"北马其顿", "2332", "261347", "231179", "8285"},
         {"尼日利亚", "250", "252753", "228137", "3134"},
         {"阿尔巴尼亚", "2156", "252577", "225835", "3323"},
         {"博茨瓦纳", "0", "245904", "235216", "2565"},
         {"塞浦路斯", "0", "243818", "124370", "724"},
         {"阿尔及利亚", "2521", "243568", "162743", "6526"},
         {"津巴布韦", "235", "228943", "216028", "5321"},
         {"莫桑比克", "460", "223112", "208116", "2163"},
         {"乌兹别克斯坦", "1174", "218477", "208018", "1551"},
         {"黑山", "0", "215950", "205416", "2535"},
         {"吉尔吉斯斯坦", "370", "197081", "185167", "2862"},
         {"留尼汪岛", "46914", "180531", "108771", "500"},
         {"阿富汗", "440", "161004", "146454", "7403"},
         {"乌干达", "196", "160907", "99157", "3502"},
         {"加纳", "0", "156392", "152907", "1384"},
         {"纳米比亚", "78", "155502", "145187", "3937"},
         {"卢森堡", "1714", "147854", "116076", "946"},
         {"老挝", "579", "132130", "7660", "534"},
         {"卢旺达", "173", "128509", "45522", "1434"},
         {"萨尔瓦多", "0", "127012", "117753", "3866"},
         {"马尔代夫", "2609", "125590", "108632", "272"},
         {"牙买加", "754", "121963", "68749", "2615"},
         {"柬埔寨", "22", "121150", "117286", "3015"},
         {"喀麦隆", "0", "114113", "106050", "1867"},
         {"特立尼达和多巴哥", "602", "108088", "84292", "3347"},
         {"瓜德罗普", "0", "105319", "2250", "773"},
         {"安哥拉", "331", "97812", "90853", "1892"},
         {"刚果（金）", "241", "84877", "50930", "1278"},
         {"塞内加尔", "160", "84709", "79072", "1939"},
         {"马拉维", "86", "84105", "68547", "2537"},
         {"马提尼克", "11620", "82813", "104", "826"},
         {"科特迪瓦", "114", "80396", "77143", "782"},
         {"法属圭亚那", "872", "74686", "11254", "363"},
         {"苏里南", "692", "72088", "49235", "1252"},
         {"斯威士兰", "46", "68205", "66567", "1371"},
         {"马耳他", "314", "66938", "62039", "541"},
         {"冰岛", "1641", "63188", "51550", "45"},
         {"斐济", "305", "62203", "58656", "791"},
         {"圭亚那合作共和国", "372", "58196", "44095", "1154"},
         {"毛里塔尼亚", "168", "57794", "51877", "937"},
         {"马达加斯加", "0", "57375", "52012", "1223"},
         {"苏丹", "684", "56595", "40329", "3411"},
         {"佛得角", "70", "55543", "54356", "393"},
         {"叙利亚", "46", "51124", "37103", "2977"},
         {"伯利兹", "1116", "49059", "38915", "624"},
         {"法属波利尼西亚", "138", "47794", "33500", "636"},
         {"加蓬", "0", "46469", "41461", "301"},
         {"巴巴多斯", "923", "41355", "33075", "277"},
         {"海峡群岛", "476", "40101", "37469", "129"},
         {"布隆迪", "96", "37170", "773", "38"},
         {"巴布亚新几内亚", "48", "36596", "35853", "597"},
         {"库拉索", "231", "36594", "33266", "222"},
         {"多哥", "49", "36421", "31558", "267"},
         {"马约特", "0", "36166", "2964", "187"},
         {"几内亚", "62", "36013", "31870", "416"},
         {"安道尔", "1676", "35028", "30112", "145"},
         {"塞舌尔", "0", "34367", "28964", "143"},
         {"坦桑尼亚", "527", "32920", "183", "778"},
         {"阿鲁巴", "119", "32562", "32013", "193"},
         {"巴哈马", "101", "32282", "24048", "731"},
         {"莱索托", "0", "32049", "20990", "690"},
         {"马里", "116", "29895", "25584", "710"},
         {"海地", "0", "28561", "24300", "783"},
         {"贝宁", "0", "26450", "25506", "163"},
         {"毛里求斯", "74", "25570", "24687", "762"},
         {"索马里", "0", "25388", "13182", "1335"},
         {"刚果（布）", "0", "23485", "19298", "371"},
         {"马恩岛", "150", "21200", "20487", "70"},
         {"布基纳法索", "0", "20591", "19967", "366"},
         {"圣卢西亚", "212", "20192", "15788", "326"},
         {"东帝汶", "8", "19879", "19740", "122"},
         {"新喀里多尼亚", "586", "17903", "13426", "283"},
         {"尼加拉瓜", "46", "17650", "4225", "216"},
         {"塔吉克斯坦", "18", "17241", "17023", "124"},
         {"南苏丹", "23", "16752", "12934", "137"},
         {"法罗群岛", "913", "16637", "7693", "17"},
         {"文莱", "0", "16148", "15682", "98"},
         {"新西兰", "58", "15842", "14549", "52"},
         {"赤道几内亚", "0", "15774", "15121", "182"},
         {"吉布提", "23", "15396", "15023", "189"},
         {"中非共和国", "229", "13840", "6859", "109"},
         {"直布罗陀", "174", "12277", "10629", "100"},
         {"格林纳达", "150", "11816", "9467", "207"},
         {"圣马力诺", "0", "11786", "10091", "108"},
         {"开曼群岛", "0", "11666", "8093", "15"},
         {"冈比亚", "0", "11572", "10156", "347"},
         {"也门", "303", "10788", "7071", "2003"},
         {"百慕大", "0", "10262", "8429", "114"},
         {"格陵兰岛", "334", "10157", "2761", "4"},
         {"厄立特里亚", "76", "9408", "8913", "96"},
         {"圣马丁岛", "36", "9203", "8183", "79"},
         {"多米尼克", "210", "8838", "8058", "51"},
         {"尼日尔", "11", "8616", "7794", "297"},
         {"列支敦士登", "125", "8406", "7920", "73"},
         {"摩纳哥", "99", "7928", "7370", "44"},
         {"科摩罗", "7", "7824", "7620", "159"},
         {"塞拉利昂", "15", "7608", "4393", "125"},
         {"几内亚比绍", "273", "7508", "6503", "154"},
         {"利比里亚", "0", "7243", "5747", "289"},
         {"乍得", "0", "7073", "4874", "190"},
         {"圣文森特和格林纳丁斯", "2", "6663", "5711", "92"},
         {"安提瓜和巴布达", "0", "6442", "5197", "126"},
         {"圣多美和普林西比", "20", "5856", "5377", "69"},
         {"英属维尔京群岛", "207", "5809", "2649", "49"},
         {"特克斯和凯科斯群岛", "63", "5659", "5383", "34"},
         {"圣基茨和尼维斯", "28", "5368", "4816", "33"},
         {"不丹", "138", "4089", "2780", "3"},
         {"圣巴泰勒米岛", "0", "3282", "462", "6"},
         {"安圭拉", "83", "2270", "2139", "7"},
         {"帕劳共和国", "141", "898", "121", "0"},
         {"圣皮埃尔", "38", "813", "587", "0"},
         {"所罗门群岛", "0", "755", "20", "5"},
         {"钻石公主号邮轮", "0", "712", "699", "13"},
         {"瓦利斯和富图纳群岛", "0", "454", "438", "7"},
         {"基里巴斯", "27", "181", "0", "0"},
         {"蒙特塞拉特", "3", "161", "148", "1"},
         {"马尔维纳斯群岛", "0", "85", "68", "0"},
         {"梵蒂冈", "0", "29", "27", "0"},
         {"萨摩亚独立国", "0", "27", "3", "0"},
         {"瓦努阿图共和国", "0", "7", "6", "1"},
         {"马绍尔群岛", "0", "7", "7", "0"},
         {"圣赫勒拿", "0", "2", "2", "0"},
         {"汤加王国", "0", "1", "1", "0"},
         {"密克罗尼西亚", "0", "1", "1", "0"}
        };

#endif //OPERATORS_EPIDEMIC_H
