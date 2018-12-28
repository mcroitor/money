#include "currency.h"

namespace mc {
    namespace currency {
        const std::map<currency_t, std::string> currency_name_ = {
            {currency_t::AED, "United Arab Emirates Dirham"},
            {currency_t::AFN, "Afghanistan Afghani"},
            {currency_t::ALL, "Albania Lek"},
            {currency_t::AMD, "Armenia Dram"},
            {currency_t::ANG, "Netherlands Antilles Guilder"},
            {currency_t::AOA, "Angola Kwanza"},
            {currency_t::ARS, "Argentina Peso"},
            {currency_t::AUD, "Australia Dollar"},
            {currency_t::AWG, "Aruba Guilder"},
            {currency_t::AZN, "Azerbaijan Manat"},
            {currency_t::BAM, "Bosnia and Herzegovina Convertible Marka"},
            {currency_t::BBD, "Barbados Dollar"},
            {currency_t::BDT, "Bangladesh Taka"},
            {currency_t::BGN, "Bulgaria Lev"},
            {currency_t::BHD, "Bahrain Dinar"},
            {currency_t::BIF, "Burundi Franc"},
            {currency_t::BMD, "Bermuda Dollar"},
            {currency_t::BND, "Brunei Darussalam Dollar"},
            {currency_t::BOB, "Bolivia Bolíviano"},
            {currency_t::BRL, "Brazil Real"},
            {currency_t::BSD, "Bahamas Dollar"},
            {currency_t::BTN, "Bhutan Ngultrum"},
            {currency_t::BWP, "Botswana Pula"},
            {currency_t::BYN, "Belarus Ruble"},
            {currency_t::BZD, "Belize Dollar"},
            {currency_t::CAD, "Canada Dollar"},
            {currency_t::CDF, "Congo / Kinshasa Franc"},
            {currency_t::CHF, "Switzerland Franc"},
            {currency_t::CLP, "Chile Peso"},
            {currency_t::CNY, "China Yuan Renminbi"},
            {currency_t::COP, "Colombia Peso"},
            {currency_t::CRC, "Costa Rica Colon"},
            {currency_t::CUC, "Cuba Convertible Peso"},
            {currency_t::CUP, "Cuba Peso"},
            {currency_t::CVE, "Cape Verde Escudo"},
            {currency_t::CZK, "Czech Republic Koruna"},
            {currency_t::DJF, "Djibouti Franc"},
            {currency_t::DKK, "Denmark Krone"},
            {currency_t::DOP, "Dominican Republic Peso"},
            {currency_t::DZD, "Algeria Dinar"},
            {currency_t::EGP, "Egypt Pound"},
            {currency_t::ERN, "Eritrea Nakfa"},
            {currency_t::ETB, "Ethiopia Birr"},
            {currency_t::EUR, "Euro Member Countries"},
            {currency_t::FJD, "Fiji Dollar"},
            {currency_t::FKP, "Falkland Islands(Malvinas) Pound"},
            {currency_t::GBP, "United Kingdom Pound"},
            {currency_t::GEL, "Georgia Lari"},
            {currency_t::GGP, "Guernsey Pound"},
            {currency_t::GHS, "Ghana Cedi"},
            {currency_t::GIP, "Gibraltar Pound"},
            {currency_t::GMD, "Gambia Dalasi"},
            {currency_t::GNF, "Guinea Franc"},
            {currency_t::GTQ, "Guatemala Quetzal"},
            {currency_t::GYD, "Guyana Dollar"},
            {currency_t::HKD, "Hong Kong Dollar"},
            {currency_t::HNL, "Honduras Lempira"},
            {currency_t::HRK, "Croatia Kuna"},
            {currency_t::HTG, "Haiti Gourde"},
            {currency_t::HUF, "Hungary Forint"},
            {currency_t::IDR, "Indonesia Rupiah"},
            {currency_t::ILS, "Israel Shekel"},
            {currency_t::IMP, "Isle of Man Pound"},
            {currency_t::INR, "India Rupee"},
            {currency_t::IQD, "Iraq Dinar"},
            {currency_t::IRR, "Iran Rial"},
            {currency_t::ISK, "Iceland Krona"},
            {currency_t::JEP, "Jersey Pound"},
            {currency_t::JMD, "Jamaica Dollar"},
            {currency_t::JOD, "Jordan Dinar"},
            {currency_t::JPY, "Japan Yen"},
            {currency_t::KES, "Kenya Shilling"},
            {currency_t::KGS, "Kyrgyzstan Som"},
            {currency_t::KHR, "Cambodia Riel"},
            {currency_t::KMF, "Comorian Franc"},
            {currency_t::KPW, "Korea(North) Won"},
            {currency_t::KRW, "Korea(South) Won"},
            {currency_t::KWD, "Kuwait Dinar"},
            {currency_t::KYD, "Cayman Islands Dollar"},
            {currency_t::KZT, "Kazakhstan Tenge"},
            {currency_t::LAK, "Laos Kip"},
            {currency_t::LBP, "Lebanon Pound"},
            {currency_t::LKR, "Sri Lanka Rupee"},
            {currency_t::LRD, "Liberia Dollar"},
            {currency_t::LSL, "Lesotho Loti"},
            {currency_t::LYD, "Libya Dinar"},
            {currency_t::MAD, "Morocco Dirham"},
            {currency_t::MDL, "Moldova Leu"},
            {currency_t::MGA, "Madagascar Ariary"},
            {currency_t::MKD, "Macedonia Denar"},
            {currency_t::MMK, "Myanmar(Burma) Kyat"},
            {currency_t::MNT, "Mongolia Tughrik"},
            {currency_t::MOP, "Macau Pataca"},
            {currency_t::MRU, "Mauritania Ouguiya"},
            {currency_t::MUR, "Mauritius Rupee"},
            {currency_t::MVR, "Maldives(Maldive Islands) Rufiyaa"},
            {currency_t::MWK, "Malawi Kwacha"},
            {currency_t::MXN, "Mexico Peso"},
            {currency_t::MYR, "Malaysia Ringgit"},
            {currency_t::MZN, "Mozambique Metical"},
            {currency_t::NAD, "Namibia Dollar"},
            {currency_t::NGN, "Nigeria Naira"},
            {currency_t::NIO, "Nicaragua Cordoba"},
            {currency_t::NOK, "Norway Krone"},
            {currency_t::NPR, "Nepal Rupee"},
            {currency_t::NZD, "New Zealand Dollar"},
            {currency_t::OMR, "Oman Rial"},
            {currency_t::PAB, "Panama Balboa"},
            {currency_t::PEN, "Peru Sol"},
            {currency_t::PGK, "Papua New Guinea Kina"},
            {currency_t::PHP, "Philippines Piso"},
            {currency_t::PKR, "Pakistan Rupee"},
            {currency_t::PLN, "Poland Zloty"},
            {currency_t::PYG, "Paraguay Guarani"},
            {currency_t::QAR, "Qatar Riyal"},
            {currency_t::RON, "Romania Leu"},
            {currency_t::RSD, "Serbia Dinar"},
            {currency_t::RUB, "Russia Ruble"},
            {currency_t::RWF, "Rwanda Franc"},
            {currency_t::SAR, "Saudi Arabia Riyal"},
            {currency_t::SBD, "Solomon Islands Dollar"},
            {currency_t::SCR, "Seychelles Rupee"},
            {currency_t::SDG, "Sudan Pound"},
            {currency_t::SEK, "Sweden Krona"},
            {currency_t::SGD, "Singapore Dollar"},
            {currency_t::SHP, "Saint Helena Pound"},
            {currency_t::SLL, "Sierra Leone Leone"},
            {currency_t::SOS, "Somalia Shilling"},
            {currency_t::SPL, "Seborga Luigino"},
            {currency_t::SRD, "Suriname Dollar"},
            {currency_t::STN, "São Tomé and Príncipe Dobra"},
            {currency_t::SVC, "El Salvador Colon"},
            {currency_t::SYP, "Syria Pound"},
            {currency_t::SZL, "Swaziland Lilangeni"},
            {currency_t::THB, "Thailand Baht"},
            {currency_t::TJS, "Tajikistan Somoni"},
            {currency_t::TMT, "Turkmenistan Manat"},
            {currency_t::TND, "Tunisia Dinar"},
            {currency_t::TOP, "Tonga Pa'anga"},
            {currency_t::TRY, "Turkey Lira"},
            {currency_t::TTD, "Trinidad and Tobago Dollar"},
            {currency_t::TVD, "Tuvalu Dollar"},
            {currency_t::TWD, "Taiwan New Dollar"},
            {currency_t::TZS, "Tanzania Shilling"},
            {currency_t::UAH, "Ukraine Hryvnia"},
            {currency_t::UGX, "Uganda Shilling"},
            {currency_t::USD, "United States Dollar"},
            {currency_t::UYU, "Uruguay Peso"},
            {currency_t::UZS, "Uzbekistan Som"},
            {currency_t::VEF, "Venezuela Bolívar"},
            {currency_t::VND, "Viet Nam Dong"},
            {currency_t::VUV, "Vanuatu Vatu"},
            {currency_t::WST, "Samoa Tala"},
            {currency_t::XAF, "Communauté Financière Africaine(BEAC) CFA Franc BEAC"},
            {currency_t::XCD, "East Caribbean Dollar"},
            {currency_t::XDR, "International Monetary Fund(IMF) Special Drawing Rights"},
            {currency_t::XOF, "Communauté Financière Africaine(BCEAO) Franc"},
            {currency_t::XPF, "Comptoirs Français du Pacifique(CFP) Franc"},
            {currency_t::YER, "Yemen Rial"},
            {currency_t::ZAR, "South Africa Rand"},
            {currency_t::ZMW, "Zambia Kwacha"},
            {currency_t::ZWD, "Zimbabwe Dollar"}
        };

        const std::map<currency_t, std::string> currency_to_shortname_ = {
            {currency_t::AED, "AED"},
            {currency_t::AFN, "AFN"},
            {currency_t::ALL, "ALL"},
            {currency_t::AMD, "AMD"},
            {currency_t::ANG, "ANG"},
            {currency_t::AOA, "AOA"},
            {currency_t::ARS, "ARS"},
            {currency_t::AUD, "AUD"},
            {currency_t::AWG, "AWG"},
            {currency_t::AZN, "AZN"},
            {currency_t::BAM, "BAM"},
            {currency_t::BBD, "BBD"},
            {currency_t::BDT, "BDT"},
            {currency_t::BGN, "BGN"},
            {currency_t::BHD, "BHD"},
            {currency_t::BIF, "BIF"},
            {currency_t::BMD, "BMD"},
            {currency_t::BND, "BND"},
            {currency_t::BOB, "BOB"},
            {currency_t::BRL, "BRL"},
            {currency_t::BSD, "BSD"},
            {currency_t::BTN, "BTN"},
            {currency_t::BWP, "BWP"},
            {currency_t::BYN, "BYN"},
            {currency_t::BZD, "BZD"},
            {currency_t::CAD, "CAD"},
            {currency_t::CDF, "CDF"},
            {currency_t::CHF, "CHF"},
            {currency_t::CLP, "CLP"},
            {currency_t::CNY, "CNY"},
            {currency_t::COP, "COP"},
            {currency_t::CRC, "CRC"},
            {currency_t::CUC, "CUC"},
            {currency_t::CUP, "CUP"},
            {currency_t::CVE, "CVE"},
            {currency_t::CZK, "CZK"},
            {currency_t::DJF, "DJF"},
            {currency_t::DKK, "DKK"},
            {currency_t::DOP, "DOP"},
            {currency_t::DZD, "DZD"},
            {currency_t::EGP, "EGP"},
            {currency_t::ERN, "ERN"},
            {currency_t::ETB, "ETB"},
            {currency_t::EUR, "EUR"},
            {currency_t::FJD, "FJD"},
            {currency_t::FKP, "FKP"},
            {currency_t::GBP, "GBP"},
            {currency_t::GEL, "GEL"},
            {currency_t::GGP, "GGP"},
            {currency_t::GHS, "GHS"},
            {currency_t::GIP, "GIP"},
            {currency_t::GMD, "GMD"},
            {currency_t::GNF, "GNF"},
            {currency_t::GTQ, "GTQ"},
            {currency_t::GYD, "GYD"},
            {currency_t::HKD, "HKD"},
            {currency_t::HNL, "HNL"},
            {currency_t::HRK, "HRK"},
            {currency_t::HTG, "HTG"},
            {currency_t::HUF, "HUF"},
            {currency_t::IDR, "IDR"},
            {currency_t::ILS, "ILS"},
            {currency_t::IMP, "IMP"},
            {currency_t::INR, "INR"},
            {currency_t::IQD, "IQD"},
            {currency_t::IRR, "IRR"},
            {currency_t::ISK, "ISK"},
            {currency_t::JEP, "JEP"},
            {currency_t::JMD, "JMD"},
            {currency_t::JOD, "JOD"},
            {currency_t::JPY, "JPY"},
            {currency_t::KES, "KES"},
            {currency_t::KGS, "KGS"},
            {currency_t::KHR, "KHR"},
            {currency_t::KMF, "KMF"},
            {currency_t::KPW, "KPW"},
            {currency_t::KRW, "KRW"},
            {currency_t::KWD, "KWD"},
            {currency_t::KYD, "KYD"},
            {currency_t::KZT, "KZT"},
            {currency_t::LAK, "LAK"},
            {currency_t::LBP, "LBP"},
            {currency_t::LKR, "LKR"},
            {currency_t::LRD, "LRD"},
            {currency_t::LSL, "LSL"},
            {currency_t::LYD, "LYD"},
            {currency_t::MAD, "MAD"},
            {currency_t::MDL, "MDL"},
            {currency_t::MGA, "MGA"},
            {currency_t::MKD, "MKD"},
            {currency_t::MMK, "MMK"},
            {currency_t::MNT, "MNT"},
            {currency_t::MOP, "MOP"},
            {currency_t::MRU, "MRU"},
            {currency_t::MUR, "MUR"},
            {currency_t::MVR, "MVR"},
            {currency_t::MWK, "MWK"},
            {currency_t::MXN, "MXN"},
            {currency_t::MYR, "MYR"},
            {currency_t::MZN, "MZN"},
            {currency_t::NAD, "NAD"},
            {currency_t::NGN, "NGN"},
            {currency_t::NIO, "NIO"},
            {currency_t::NOK, "NOK"},
            {currency_t::NPR, "NPR"},
            {currency_t::NZD, "NZD"},
            {currency_t::OMR, "OMR"},
            {currency_t::PAB, "PAB"},
            {currency_t::PEN, "PEN"},
            {currency_t::PGK, "PGK"},
            {currency_t::PHP, "PHP"},
            {currency_t::PKR, "PKR"},
            {currency_t::PLN, "PLN"},
            {currency_t::PYG, "PYG"},
            {currency_t::QAR, "QAR"},
            {currency_t::RON, "RON"},
            {currency_t::RSD, "RSD"},
            {currency_t::RUB, "RUB"},
            {currency_t::RWF, "RWF"},
            {currency_t::SAR, "SAR"},
            {currency_t::SBD, "SBD"},
            {currency_t::SCR, "SCR"},
            {currency_t::SDG, "SDG"},
            {currency_t::SEK, "SEK"},
            {currency_t::SGD, "SGD"},
            {currency_t::SHP, "SHP"},
            {currency_t::SLL, "SLL"},
            {currency_t::SOS, "SOS"},
            {currency_t::SPL, "SPL"},
            {currency_t::SRD, "SRD"},
            {currency_t::STN, "STN"},
            {currency_t::SVC, "SVC"},
            {currency_t::SYP, "SYP"},
            {currency_t::SZL, "SZL"},
            {currency_t::THB, "THB"},
            {currency_t::TJS, "TJS"},
            {currency_t::TMT, "TMT"},
            {currency_t::TND, "TND"},
            {currency_t::TOP, "TOP"},
            {currency_t::TRY, "TRY"},
            {currency_t::TTD, "TTD"},
            {currency_t::TVD, "TVD"},
            {currency_t::TWD, "TWD"},
            {currency_t::TZS, "TZS"},
            {currency_t::UAH, "UAH"},
            {currency_t::UGX, "UGX"},
            {currency_t::USD, "USD"},
            {currency_t::UYU, "UYU"},
            {currency_t::UZS, "UZS"},
            {currency_t::VEF, "VEF"},
            {currency_t::VND, "VND"},
            {currency_t::VUV, "VUV"},
            {currency_t::WST, "WST"},
            {currency_t::XAF, "XAF"},
            {currency_t::XCD, "XCD"},
            {currency_t::XDR, "XDR"},
            {currency_t::XOF, "XOF"},
            {currency_t::XPF, "XPF"},
            {currency_t::YER, "YER"},
            {currency_t::ZAR, "ZAR"},
            {currency_t::ZMW, "ZMW"},
            {currency_t::ZWD, "ZWD"}
        };

        const std::map<std::string, currency_t> shortname_to_currency_ = {
            {"AED", currency_t::AED},
            {"AFN", currency_t::AFN},
            {"ALL", currency_t::ALL},
            {"AMD", currency_t::AMD},
            {"ANG", currency_t::ANG},
            {"AOA", currency_t::AOA},
            {"ARS", currency_t::ARS},
            {"AUD", currency_t::AUD},
            {"AWG", currency_t::AWG},
            {"AZN", currency_t::AZN},
            {"BAM", currency_t::BAM},
            {"BBD", currency_t::BBD},
            {"BDT", currency_t::BDT},
            {"BGN", currency_t::BGN},
            {"BHD", currency_t::BHD},
            {"BIF", currency_t::BIF},
            {"BMD", currency_t::BMD},
            {"BND", currency_t::BND},
            {"BOB", currency_t::BOB},
            {"BRL", currency_t::BRL},
            {"BSD", currency_t::BSD},
            {"BTN", currency_t::BTN},
            {"BWP", currency_t::BWP},
            {"BYN", currency_t::BYN},
            {"BZD", currency_t::BZD},
            {"CAD", currency_t::CAD},
            {"CDF", currency_t::CDF},
            {"CHF", currency_t::CHF},
            {"CLP", currency_t::CLP},
            {"CNY", currency_t::CNY},
            {"COP", currency_t::COP},
            {"CRC", currency_t::CRC},
            {"CUC", currency_t::CUC},
            {"CUP", currency_t::CUP},
            {"CVE", currency_t::CVE},
            {"CZK", currency_t::CZK},
            {"DJF", currency_t::DJF},
            {"DKK", currency_t::DKK},
            {"DOP", currency_t::DOP},
            {"DZD", currency_t::DZD},
            {"EGP", currency_t::EGP},
            {"ERN", currency_t::ERN},
            {"ETB", currency_t::ETB},
            {"EUR", currency_t::EUR},
            {"FJD", currency_t::FJD},
            {"FKP", currency_t::FKP},
            {"GBP", currency_t::GBP},
            {"GEL", currency_t::GEL},
            {"GGP", currency_t::GGP},
            {"GHS", currency_t::GHS},
            {"GIP", currency_t::GIP},
            {"GMD", currency_t::GMD},
            {"GNF", currency_t::GNF},
            {"GTQ", currency_t::GTQ},
            {"GYD", currency_t::GYD},
            {"HKD", currency_t::HKD},
            {"HNL", currency_t::HNL},
            {"HRK", currency_t::HRK},
            {"HTG", currency_t::HTG},
            {"HUF", currency_t::HUF},
            {"IDR", currency_t::IDR},
            {"ILS", currency_t::ILS},
            {"IMP", currency_t::IMP},
            {"INR", currency_t::INR},
            {"IQD", currency_t::IQD},
            {"IRR", currency_t::IRR},
            {"ISK", currency_t::ISK},
            {"JEP", currency_t::JEP},
            {"JMD", currency_t::JMD},
            {"JOD", currency_t::JOD},
            {"JPY", currency_t::JPY},
            {"KES", currency_t::KES},
            {"KGS", currency_t::KGS},
            {"KHR", currency_t::KHR},
            {"KMF", currency_t::KMF},
            {"KPW", currency_t::KPW},
            {"KRW", currency_t::KRW},
            {"KWD", currency_t::KWD},
            {"KYD", currency_t::KYD},
            {"KZT", currency_t::KZT},
            {"LAK", currency_t::LAK},
            {"LBP", currency_t::LBP},
            {"LKR", currency_t::LKR},
            {"LRD", currency_t::LRD},
            {"LSL", currency_t::LSL},
            {"LYD", currency_t::LYD},
            {"MAD", currency_t::MAD},
            {"MDL", currency_t::MDL},
            {"MGA", currency_t::MGA},
            {"MKD", currency_t::MKD},
            {"MMK", currency_t::MMK},
            {"MNT", currency_t::MNT},
            {"MOP", currency_t::MOP},
            {"MRU", currency_t::MRU},
            {"MUR", currency_t::MUR},
            {"MVR", currency_t::MVR},
            {"MWK", currency_t::MWK},
            {"MXN", currency_t::MXN},
            {"MYR", currency_t::MYR},
            {"MZN", currency_t::MZN},
            {"NAD", currency_t::NAD},
            {"NGN", currency_t::NGN},
            {"NIO", currency_t::NIO},
            {"NOK", currency_t::NOK},
            {"NPR", currency_t::NPR},
            {"NZD", currency_t::NZD},
            {"OMR", currency_t::OMR},
            {"PAB", currency_t::PAB},
            {"PEN", currency_t::PEN},
            {"PGK", currency_t::PGK},
            {"PHP", currency_t::PHP},
            {"PKR", currency_t::PKR},
            {"PLN", currency_t::PLN},
            {"PYG", currency_t::PYG},
            {"QAR", currency_t::QAR},
            {"RON", currency_t::RON},
            {"RSD", currency_t::RSD},
            {"RUB", currency_t::RUB},
            {"RWF", currency_t::RWF},
            {"SAR", currency_t::SAR},
            {"SBD", currency_t::SBD},
            {"SCR", currency_t::SCR},
            {"SDG", currency_t::SDG},
            {"SEK", currency_t::SEK},
            {"SGD", currency_t::SGD},
            {"SHP", currency_t::SHP},
            {"SLL", currency_t::SLL},
            {"SOS", currency_t::SOS},
            {"SPL", currency_t::SPL},
            {"SRD", currency_t::SRD},
            {"STN", currency_t::STN},
            {"SVC", currency_t::SVC},
            {"SYP", currency_t::SYP},
            {"SZL", currency_t::SZL},
            {"THB", currency_t::THB},
            {"TJS", currency_t::TJS},
            {"TMT", currency_t::TMT},
            {"TND", currency_t::TND},
            {"TOP", currency_t::TOP},
            {"TRY", currency_t::TRY},
            {"TTD", currency_t::TTD},
            {"TVD", currency_t::TVD},
            {"TWD", currency_t::TWD},
            {"TZS", currency_t::TZS},
            {"UAH", currency_t::UAH},
            {"UGX", currency_t::UGX},
            {"USD", currency_t::USD},
            {"UYU", currency_t::UYU},
            {"UZS", currency_t::UZS},
            {"VEF", currency_t::VEF},
            {"VND", currency_t::VND},
            {"VUV", currency_t::VUV},
            {"WST", currency_t::WST},
            {"XAF", currency_t::XAF},
            {"XCD", currency_t::XCD},
            {"XDR", currency_t::XDR},
            {"XOF", currency_t::XOF},
            {"XPF", currency_t::XPF},
            {"YER", currency_t::YER},
            {"ZAR", currency_t::ZAR},
            {"ZMW", currency_t::ZMW},
            {"ZWD", currency_t::ZWD}
        };

        std::string to_string(currency_t c) {
            if(currency_name_.find(c) == currency_name_.end()){
                throw unknown_currency();
            }
            return currency_name_.at(c);
        }

        std::string to_shortname(currency_t c) {
            if(currency_name_.find(c) == currency_name_.end()){
                throw unknown_currency();
            }
            return currency_to_shortname_.at(c);
        }

        currency_t to_currency(std::string sn) {
            if(shortname_to_currency_.find(sn) == shortname_to_currency_.end()){
                throw unknown_currency_shortname();
            }
            return shortname_to_currency_.at(sn);
        }
        
        // exceptions
        const char* unknown_currency::what() const noexcept{
            return "unknown currency";
        }
        
        const char* unknown_currency_shortname::what() const noexcept{
            return "unknown currency short name";
        }
    }
}