
#include <vector>
#include "Program.h"
#include "Declarations.h"
#include "Statements.h"
#include "Exprs.h"
#include "Terms.h"
#include <iostream>


// Generated from /home/ayushsahi/csc488/minicc-internal/grammars/MiniC.g4 by ANTLR 4.11.1


#include "MiniCListener.h"
#include "MiniCVisitor.h"

#include "MiniCParser.h"


using namespace antlrcpp;
using namespace minicc;

using namespace antlr4;

namespace {

struct MiniCParserStaticData final {
  MiniCParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MiniCParserStaticData(const MiniCParserStaticData&) = delete;
  MiniCParserStaticData(MiniCParserStaticData&&) = delete;
  MiniCParserStaticData& operator=(const MiniCParserStaticData&) = delete;
  MiniCParserStaticData& operator=(MiniCParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag minicParserOnceFlag;
MiniCParserStaticData *minicParserStaticData = nullptr;

void minicParserInitialize() {
  assert(minicParserStaticData == nullptr);
  auto staticData = std::make_unique<MiniCParserStaticData>(
    std::vector<std::string>{
      "prog", "preamble", "decl", "vardecl", "scope", "stmt", "varlist", 
      "varlistentry", "vartype", "rettype", "parameters", "parameterlist", 
      "parameterentry", "expropt", "expr", "var", "arguments", "argumentlist", 
      "varname", "funcname", "parametername"
    },
    std::vector<std::string>{
      "", "'#include'", "'\"minicio.h\"'", "'('", "')'", "';'", "'{'", "'}'", 
      "'if'", "'else'", "'for'", "'while'", "'break'", "'return'", "','", 
      "'['", "']'", "'int'", "'bool'", "'char'", "'void'", "'-'", "'*'", 
      "'/'", "'+'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", "'!'", 
      "'&&'", "'||'", "'='", "'true'", "'false'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "ID", "INT", "CHAR", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,343,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,1,
  	0,1,0,1,0,3,0,47,8,0,1,0,1,0,1,0,5,0,52,8,0,10,0,12,0,55,9,0,1,0,1,0,
  	1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,3,2,81,8,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,5,4,
  	92,8,4,10,4,12,4,95,9,4,1,4,1,4,1,4,5,4,100,8,4,10,4,12,4,103,9,4,1,4,
  	1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,3,5,160,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,171,8,6,10,
  	6,12,6,174,9,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,185,8,7,1,8,1,
  	8,1,8,1,8,1,8,1,8,3,8,193,8,8,1,9,1,9,1,9,1,9,1,9,3,9,200,8,9,1,10,1,
  	10,1,10,1,10,3,10,206,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,5,11,217,8,11,10,11,12,11,220,9,11,1,12,1,12,1,12,1,12,1,13,1,13,1,
  	13,1,13,3,13,230,8,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,3,14,271,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,5,14,298,8,14,10,14,12,14,301,9,14,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,3,15,312,8,15,1,16,1,16,1,16,1,16,3,16,318,8,16,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,329,8,17,10,17,12,17,332,
  	9,17,1,18,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,20,1,20,0,4,12,22,28,34,
  	21,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0,3,1,0,
  	22,23,2,0,21,21,24,24,1,0,25,30,361,0,46,1,0,0,0,2,58,1,0,0,0,4,80,1,
  	0,0,0,6,82,1,0,0,0,8,87,1,0,0,0,10,159,1,0,0,0,12,161,1,0,0,0,14,184,
  	1,0,0,0,16,192,1,0,0,0,18,199,1,0,0,0,20,205,1,0,0,0,22,207,1,0,0,0,24,
  	221,1,0,0,0,26,229,1,0,0,0,28,270,1,0,0,0,30,311,1,0,0,0,32,317,1,0,0,
  	0,34,319,1,0,0,0,36,333,1,0,0,0,38,336,1,0,0,0,40,339,1,0,0,0,42,43,3,
  	2,1,0,43,44,6,0,-1,0,44,47,1,0,0,0,45,47,6,0,-1,0,46,42,1,0,0,0,46,45,
  	1,0,0,0,47,53,1,0,0,0,48,49,3,4,2,0,49,50,6,0,-1,0,50,52,1,0,0,0,51,48,
  	1,0,0,0,52,55,1,0,0,0,53,51,1,0,0,0,53,54,1,0,0,0,54,56,1,0,0,0,55,53,
  	1,0,0,0,56,57,5,0,0,1,57,1,1,0,0,0,58,59,5,1,0,0,59,60,5,2,0,0,60,3,1,
  	0,0,0,61,62,3,6,3,0,62,63,6,2,-1,0,63,81,1,0,0,0,64,65,3,18,9,0,65,66,
  	3,38,19,0,66,67,5,3,0,0,67,68,3,20,10,0,68,69,5,4,0,0,69,70,3,8,4,0,70,
  	71,6,2,-1,0,71,81,1,0,0,0,72,73,3,18,9,0,73,74,3,38,19,0,74,75,5,3,0,
  	0,75,76,3,20,10,0,76,77,5,4,0,0,77,78,5,5,0,0,78,79,6,2,-1,0,79,81,1,
  	0,0,0,80,61,1,0,0,0,80,64,1,0,0,0,80,72,1,0,0,0,81,5,1,0,0,0,82,83,3,
  	16,8,0,83,84,3,12,6,0,84,85,5,5,0,0,85,86,6,3,-1,0,86,7,1,0,0,0,87,93,
  	5,6,0,0,88,89,3,6,3,0,89,90,6,4,-1,0,90,92,1,0,0,0,91,88,1,0,0,0,92,95,
  	1,0,0,0,93,91,1,0,0,0,93,94,1,0,0,0,94,101,1,0,0,0,95,93,1,0,0,0,96,97,
  	3,10,5,0,97,98,6,4,-1,0,98,100,1,0,0,0,99,96,1,0,0,0,100,103,1,0,0,0,
  	101,99,1,0,0,0,101,102,1,0,0,0,102,104,1,0,0,0,103,101,1,0,0,0,104,105,
  	5,7,0,0,105,106,6,4,-1,0,106,9,1,0,0,0,107,108,3,28,14,0,108,109,5,5,
  	0,0,109,110,6,5,-1,0,110,160,1,0,0,0,111,112,5,8,0,0,112,113,5,3,0,0,
  	113,114,3,28,14,0,114,115,5,4,0,0,115,116,3,10,5,0,116,117,6,5,-1,0,117,
  	160,1,0,0,0,118,119,5,8,0,0,119,120,5,3,0,0,120,121,3,28,14,0,121,122,
  	5,4,0,0,122,123,3,10,5,0,123,124,5,9,0,0,124,125,3,10,5,0,125,126,6,5,
  	-1,0,126,160,1,0,0,0,127,128,5,10,0,0,128,129,5,3,0,0,129,130,3,26,13,
  	0,130,131,5,5,0,0,131,132,3,26,13,0,132,133,5,5,0,0,133,134,3,26,13,0,
  	134,135,5,4,0,0,135,136,3,10,5,0,136,137,6,5,-1,0,137,160,1,0,0,0,138,
  	139,5,11,0,0,139,140,5,3,0,0,140,141,3,28,14,0,141,142,5,4,0,0,142,143,
  	3,10,5,0,143,144,6,5,-1,0,144,160,1,0,0,0,145,146,5,12,0,0,146,147,5,
  	5,0,0,147,160,6,5,-1,0,148,149,5,13,0,0,149,150,5,5,0,0,150,160,6,5,-1,
  	0,151,152,5,13,0,0,152,153,3,28,14,0,153,154,5,5,0,0,154,155,6,5,-1,0,
  	155,160,1,0,0,0,156,157,3,8,4,0,157,158,6,5,-1,0,158,160,1,0,0,0,159,
  	107,1,0,0,0,159,111,1,0,0,0,159,118,1,0,0,0,159,127,1,0,0,0,159,138,1,
  	0,0,0,159,145,1,0,0,0,159,148,1,0,0,0,159,151,1,0,0,0,159,156,1,0,0,0,
  	160,11,1,0,0,0,161,162,6,6,-1,0,162,163,3,14,7,0,163,164,6,6,-1,0,164,
  	172,1,0,0,0,165,166,10,1,0,0,166,167,5,14,0,0,167,168,3,14,7,0,168,169,
  	6,6,-1,0,169,171,1,0,0,0,170,165,1,0,0,0,171,174,1,0,0,0,172,170,1,0,
  	0,0,172,173,1,0,0,0,173,13,1,0,0,0,174,172,1,0,0,0,175,176,3,36,18,0,
  	176,177,6,7,-1,0,177,185,1,0,0,0,178,179,3,36,18,0,179,180,5,15,0,0,180,
  	181,5,38,0,0,181,182,5,16,0,0,182,183,6,7,-1,0,183,185,1,0,0,0,184,175,
  	1,0,0,0,184,178,1,0,0,0,185,15,1,0,0,0,186,187,5,17,0,0,187,193,6,8,-1,
  	0,188,189,5,18,0,0,189,193,6,8,-1,0,190,191,5,19,0,0,191,193,6,8,-1,0,
  	192,186,1,0,0,0,192,188,1,0,0,0,192,190,1,0,0,0,193,17,1,0,0,0,194,195,
  	5,20,0,0,195,200,6,9,-1,0,196,197,3,16,8,0,197,198,6,9,-1,0,198,200,1,
  	0,0,0,199,194,1,0,0,0,199,196,1,0,0,0,200,19,1,0,0,0,201,206,6,10,-1,
  	0,202,203,3,22,11,0,203,204,6,10,-1,0,204,206,1,0,0,0,205,201,1,0,0,0,
  	205,202,1,0,0,0,206,21,1,0,0,0,207,208,6,11,-1,0,208,209,3,24,12,0,209,
  	210,6,11,-1,0,210,218,1,0,0,0,211,212,10,1,0,0,212,213,5,14,0,0,213,214,
  	3,24,12,0,214,215,6,11,-1,0,215,217,1,0,0,0,216,211,1,0,0,0,217,220,1,
  	0,0,0,218,216,1,0,0,0,218,219,1,0,0,0,219,23,1,0,0,0,220,218,1,0,0,0,
  	221,222,3,16,8,0,222,223,3,40,20,0,223,224,6,12,-1,0,224,25,1,0,0,0,225,
  	226,3,28,14,0,226,227,6,13,-1,0,227,230,1,0,0,0,228,230,6,13,-1,0,229,
  	225,1,0,0,0,229,228,1,0,0,0,230,27,1,0,0,0,231,232,6,14,-1,0,232,233,
  	5,38,0,0,233,271,6,14,-1,0,234,235,5,39,0,0,235,271,6,14,-1,0,236,237,
  	5,21,0,0,237,238,3,28,14,14,238,239,6,14,-1,0,239,271,1,0,0,0,240,241,
  	5,31,0,0,241,242,3,28,14,10,242,243,6,14,-1,0,243,271,1,0,0,0,244,245,
  	3,30,15,0,245,246,5,34,0,0,246,247,3,28,14,7,247,248,6,14,-1,0,248,271,
  	1,0,0,0,249,250,5,35,0,0,250,271,6,14,-1,0,251,252,5,36,0,0,252,271,6,
  	14,-1,0,253,254,5,3,0,0,254,255,3,28,14,0,255,256,5,4,0,0,256,257,6,14,
  	-1,0,257,271,1,0,0,0,258,259,3,30,15,0,259,260,6,14,-1,0,260,271,1,0,
  	0,0,261,262,3,38,19,0,262,263,5,3,0,0,263,264,3,32,16,0,264,265,5,4,0,
  	0,265,266,6,14,-1,0,266,271,1,0,0,0,267,268,3,40,20,0,268,269,6,14,-1,
  	0,269,271,1,0,0,0,270,231,1,0,0,0,270,234,1,0,0,0,270,236,1,0,0,0,270,
  	240,1,0,0,0,270,244,1,0,0,0,270,249,1,0,0,0,270,251,1,0,0,0,270,253,1,
  	0,0,0,270,258,1,0,0,0,270,261,1,0,0,0,270,267,1,0,0,0,271,299,1,0,0,0,
  	272,273,10,13,0,0,273,274,7,0,0,0,274,275,3,28,14,14,275,276,6,14,-1,
  	0,276,298,1,0,0,0,277,278,10,12,0,0,278,279,7,1,0,0,279,280,3,28,14,13,
  	280,281,6,14,-1,0,281,298,1,0,0,0,282,283,10,11,0,0,283,284,7,2,0,0,284,
  	285,3,28,14,12,285,286,6,14,-1,0,286,298,1,0,0,0,287,288,10,9,0,0,288,
  	289,5,32,0,0,289,290,3,28,14,10,290,291,6,14,-1,0,291,298,1,0,0,0,292,
  	293,10,8,0,0,293,294,5,33,0,0,294,295,3,28,14,9,295,296,6,14,-1,0,296,
  	298,1,0,0,0,297,272,1,0,0,0,297,277,1,0,0,0,297,282,1,0,0,0,297,287,1,
  	0,0,0,297,292,1,0,0,0,298,301,1,0,0,0,299,297,1,0,0,0,299,300,1,0,0,0,
  	300,29,1,0,0,0,301,299,1,0,0,0,302,303,3,36,18,0,303,304,6,15,-1,0,304,
  	312,1,0,0,0,305,306,3,36,18,0,306,307,5,15,0,0,307,308,3,28,14,0,308,
  	309,5,16,0,0,309,310,6,15,-1,0,310,312,1,0,0,0,311,302,1,0,0,0,311,305,
  	1,0,0,0,312,31,1,0,0,0,313,318,6,16,-1,0,314,315,3,34,17,0,315,316,6,
  	16,-1,0,316,318,1,0,0,0,317,313,1,0,0,0,317,314,1,0,0,0,318,33,1,0,0,
  	0,319,320,6,17,-1,0,320,321,3,28,14,0,321,322,6,17,-1,0,322,330,1,0,0,
  	0,323,324,10,1,0,0,324,325,5,14,0,0,325,326,3,28,14,0,326,327,6,17,-1,
  	0,327,329,1,0,0,0,328,323,1,0,0,0,329,332,1,0,0,0,330,328,1,0,0,0,330,
  	331,1,0,0,0,331,35,1,0,0,0,332,330,1,0,0,0,333,334,5,37,0,0,334,335,6,
  	18,-1,0,335,37,1,0,0,0,336,337,5,37,0,0,337,338,6,19,-1,0,338,39,1,0,
  	0,0,339,340,5,37,0,0,340,341,6,20,-1,0,341,41,1,0,0,0,19,46,53,80,93,
  	101,159,172,184,192,199,205,218,229,270,297,299,311,317,330
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  minicParserStaticData = staticData.release();
}

}

MiniCParser::MiniCParser(TokenStream *input) : MiniCParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MiniCParser::MiniCParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MiniCParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *minicParserStaticData->atn, minicParserStaticData->decisionToDFA, minicParserStaticData->sharedContextCache, options);
}

MiniCParser::~MiniCParser() {
  delete _interpreter;
}

const atn::ATN& MiniCParser::getATN() const {
  return *minicParserStaticData->atn;
}

std::string MiniCParser::getGrammarFileName() const {
  return "MiniC.g4";
}

const std::vector<std::string>& MiniCParser::getRuleNames() const {
  return minicParserStaticData->ruleNames;
}

const dfa::Vocabulary& MiniCParser::getVocabulary() const {
  return minicParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MiniCParser::getSerializedATN() const {
  return minicParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

MiniCParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ProgContext::EOF() {
  return getToken(MiniCParser::EOF, 0);
}

MiniCParser::PreambleContext* MiniCParser::ProgContext::preamble() {
  return getRuleContext<MiniCParser::PreambleContext>(0);
}

std::vector<MiniCParser::DeclContext *> MiniCParser::ProgContext::decl() {
  return getRuleContexts<MiniCParser::DeclContext>();
}

MiniCParser::DeclContext* MiniCParser::ProgContext::decl(size_t i) {
  return getRuleContext<MiniCParser::DeclContext>(i);
}


size_t MiniCParser::ProgContext::getRuleIndex() const {
  return MiniCParser::RuleProg;
}

void MiniCParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void MiniCParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


std::any MiniCParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ProgContext* MiniCParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, MiniCParser::RuleProg);

      antlrcpp::downCast<ProgContext *>(_localctx)->val =  new minicc::Program();
      _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__0: {
        setState(42);
        preamble();
         _localctx->val->setSyslibFlag(true); 
        break;
      }

      case MiniCParser::EOF:
      case MiniCParser::T__16:
      case MiniCParser::T__17:
      case MiniCParser::T__18:
      case MiniCParser::T__19: {
         _localctx->val->setSyslibFlag(false); 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1966080) != 0) {
      setState(48);
      antlrcpp::downCast<ProgContext *>(_localctx)->declContext = decl();
      _localctx->val->addChild(antlrcpp::downCast<ProgContext *>(_localctx)->declContext->val); 
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(56);
    match(MiniCParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreambleContext ------------------------------------------------------------------

MiniCParser::PreambleContext::PreambleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::PreambleContext::getRuleIndex() const {
  return MiniCParser::RulePreamble;
}

void MiniCParser::PreambleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreamble(this);
}

void MiniCParser::PreambleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreamble(this);
}


std::any MiniCParser::PreambleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitPreamble(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::PreambleContext* MiniCParser::preamble() {
  PreambleContext *_localctx = _tracker.createInstance<PreambleContext>(_ctx, getState());
  enterRule(_localctx, 2, MiniCParser::RulePreamble);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(MiniCParser::T__0);
    setState(59);
    match(MiniCParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

MiniCParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VardeclContext* MiniCParser::DeclContext::vardecl() {
  return getRuleContext<MiniCParser::VardeclContext>(0);
}

MiniCParser::RettypeContext* MiniCParser::DeclContext::rettype() {
  return getRuleContext<MiniCParser::RettypeContext>(0);
}

MiniCParser::FuncnameContext* MiniCParser::DeclContext::funcname() {
  return getRuleContext<MiniCParser::FuncnameContext>(0);
}

MiniCParser::ParametersContext* MiniCParser::DeclContext::parameters() {
  return getRuleContext<MiniCParser::ParametersContext>(0);
}

MiniCParser::ScopeContext* MiniCParser::DeclContext::scope() {
  return getRuleContext<MiniCParser::ScopeContext>(0);
}


size_t MiniCParser::DeclContext::getRuleIndex() const {
  return MiniCParser::RuleDecl;
}

void MiniCParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void MiniCParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


std::any MiniCParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::DeclContext* MiniCParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, MiniCParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(80);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(61);
      antlrcpp::downCast<DeclContext *>(_localctx)->vardeclContext = vardecl();
      antlrcpp::downCast<DeclContext *>(_localctx)->val =  antlrcpp::downCast<DeclContext *>(_localctx)->vardeclContext->val; 
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(64);
      antlrcpp::downCast<DeclContext *>(_localctx)->rettypeContext = rettype();
      setState(65);
      antlrcpp::downCast<DeclContext *>(_localctx)->funcnameContext = funcname();
      setState(66);
      match(MiniCParser::T__2);
      setState(67);
      antlrcpp::downCast<DeclContext *>(_localctx)->parametersContext = parameters();
      setState(68);
      match(MiniCParser::T__3);
      setState(69);
      antlrcpp::downCast<DeclContext *>(_localctx)->scopeContext = scope();

                  antlrcpp::downCast<DeclContext *>(_localctx)->func =  new minicc::FuncDeclaration();
                  _localctx->func->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                  _localctx->func->addChild(antlrcpp::downCast<DeclContext *>(_localctx)->rettypeContext->val);
                  _localctx->func->addChild(antlrcpp::downCast<DeclContext *>(_localctx)->funcnameContext->val);
                  for (size_t i = 0; i < antlrcpp::downCast<DeclContext *>(_localctx)->parametersContext->val.size(); i++)
                      _localctx->func->addChild(antlrcpp::downCast<DeclContext *>(_localctx)->parametersContext->val[i]);
                  _localctx->func->addChild(antlrcpp::downCast<DeclContext *>(_localctx)->scopeContext->val);
                  _localctx->func->setHasBody(true);
                  antlrcpp::downCast<DeclContext *>(_localctx)->val =  _localctx->func;
              
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(72);
      antlrcpp::downCast<DeclContext *>(_localctx)->rettypeContext = rettype();
      setState(73);
      antlrcpp::downCast<DeclContext *>(_localctx)->funcnameContext = funcname();
      setState(74);
      match(MiniCParser::T__2);
      setState(75);
      antlrcpp::downCast<DeclContext *>(_localctx)->parametersContext = parameters();
      setState(76);
      match(MiniCParser::T__3);
      setState(77);
      match(MiniCParser::T__4);

                  antlrcpp::downCast<DeclContext *>(_localctx)->func =  new minicc::FuncDeclaration();
                  _localctx->func->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                  _localctx->func->addChild(antlrcpp::downCast<DeclContext *>(_localctx)->rettypeContext->val);
                  _localctx->func->addChild(antlrcpp::downCast<DeclContext *>(_localctx)->funcnameContext->val);
                  for (size_t i = 0; i < antlrcpp::downCast<DeclContext *>(_localctx)->parametersContext->val.size(); i++)
                      _localctx->func->addChild(antlrcpp::downCast<DeclContext *>(_localctx)->parametersContext->val[i]);
                  _localctx->func->setHasBody(false);
                  antlrcpp::downCast<DeclContext *>(_localctx)->val =  _localctx->func;
              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VardeclContext ------------------------------------------------------------------

MiniCParser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::VardeclContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}

MiniCParser::VarlistContext* MiniCParser::VardeclContext::varlist() {
  return getRuleContext<MiniCParser::VarlistContext>(0);
}


size_t MiniCParser::VardeclContext::getRuleIndex() const {
  return MiniCParser::RuleVardecl;
}

void MiniCParser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void MiniCParser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}


std::any MiniCParser::VardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVardecl(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VardeclContext* MiniCParser::vardecl() {
  VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, getState());
  enterRule(_localctx, 6, MiniCParser::RuleVardecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    antlrcpp::downCast<VardeclContext *>(_localctx)->vartypeContext = vartype();
    setState(83);
    antlrcpp::downCast<VardeclContext *>(_localctx)->varlistContext = varlist(0);
    setState(84);
    match(MiniCParser::T__4);

            antlrcpp::downCast<VardeclContext *>(_localctx)->val =  new minicc::VarDeclaration();
            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            _localctx->val->addChild(antlrcpp::downCast<VardeclContext *>(_localctx)->vartypeContext->val);
            for (size_t i = 0; i < antlrcpp::downCast<VardeclContext *>(_localctx)->varlistContext->val.size(); i++)
                _localctx->val->addChild(antlrcpp::downCast<VardeclContext *>(_localctx)->varlistContext->val[i]);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

MiniCParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniCParser::VardeclContext *> MiniCParser::ScopeContext::vardecl() {
  return getRuleContexts<MiniCParser::VardeclContext>();
}

MiniCParser::VardeclContext* MiniCParser::ScopeContext::vardecl(size_t i) {
  return getRuleContext<MiniCParser::VardeclContext>(i);
}

std::vector<MiniCParser::StmtContext *> MiniCParser::ScopeContext::stmt() {
  return getRuleContexts<MiniCParser::StmtContext>();
}

MiniCParser::StmtContext* MiniCParser::ScopeContext::stmt(size_t i) {
  return getRuleContext<MiniCParser::StmtContext>(i);
}


size_t MiniCParser::ScopeContext::getRuleIndex() const {
  return MiniCParser::RuleScope;
}

void MiniCParser::ScopeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScope(this);
}

void MiniCParser::ScopeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScope(this);
}


std::any MiniCParser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ScopeContext* MiniCParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 8, MiniCParser::RuleScope);

      antlrcpp::downCast<ScopeContext *>(_localctx)->val =  new minicc::ScopeStatement();
      _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
      antlrcpp::downCast<ScopeContext *>(_localctx)->declcnt =  0;

  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(MiniCParser::T__5);
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 917504) != 0) {
      setState(88);
      antlrcpp::downCast<ScopeContext *>(_localctx)->vardeclContext = vardecl();

              _localctx->val->addChild(antlrcpp::downCast<ScopeContext *>(_localctx)->vardeclContext->val);
              _localctx->declcnt ++;
          
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1067301485896) != 0) {
      setState(96);
      antlrcpp::downCast<ScopeContext *>(_localctx)->stmtContext = stmt();

              _localctx->val->addChild(antlrcpp::downCast<ScopeContext *>(_localctx)->stmtContext->val);
          
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(104);
    match(MiniCParser::T__6);

            _localctx->val->setNumVarDecl(_localctx->declcnt);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

MiniCParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::StmtContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

std::vector<MiniCParser::StmtContext *> MiniCParser::StmtContext::stmt() {
  return getRuleContexts<MiniCParser::StmtContext>();
}

MiniCParser::StmtContext* MiniCParser::StmtContext::stmt(size_t i) {
  return getRuleContext<MiniCParser::StmtContext>(i);
}

std::vector<MiniCParser::ExproptContext *> MiniCParser::StmtContext::expropt() {
  return getRuleContexts<MiniCParser::ExproptContext>();
}

MiniCParser::ExproptContext* MiniCParser::StmtContext::expropt(size_t i) {
  return getRuleContext<MiniCParser::ExproptContext>(i);
}

MiniCParser::ScopeContext* MiniCParser::StmtContext::scope() {
  return getRuleContext<MiniCParser::ScopeContext>(0);
}


size_t MiniCParser::StmtContext::getRuleIndex() const {
  return MiniCParser::RuleStmt;
}

void MiniCParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void MiniCParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


std::any MiniCParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::StmtContext* MiniCParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 10, MiniCParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(159);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(107);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(108);
      match(MiniCParser::T__4);

              antlrcpp::downCast<StmtContext *>(_localctx)->val =  new minicc::ExprStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->val);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      match(MiniCParser::T__7);
      setState(112);
      match(MiniCParser::T__2);
      setState(113);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(114);
      match(MiniCParser::T__3);
      setState(115);
      antlrcpp::downCast<StmtContext *>(_localctx)->stmtContext = stmt();

              antlrcpp::downCast<StmtContext *>(_localctx)->val =  new minicc::IfStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->val);
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->stmtContext->val);
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(118);
      match(MiniCParser::T__7);
      setState(119);
      match(MiniCParser::T__2);
      setState(120);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(121);
      match(MiniCParser::T__3);
      setState(122);
      antlrcpp::downCast<StmtContext *>(_localctx)->s1 = stmt();
      setState(123);
      match(MiniCParser::T__8);
      setState(124);
      antlrcpp::downCast<StmtContext *>(_localctx)->s2 = stmt();

              antlrcpp::downCast<StmtContext *>(_localctx)->val =  new minicc::IfStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->val);
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->s1->val);
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->s2->val);
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(127);
      match(MiniCParser::T__9);
      setState(128);
      match(MiniCParser::T__2);
      setState(129);
      antlrcpp::downCast<StmtContext *>(_localctx)->e1 = expropt();
      setState(130);
      match(MiniCParser::T__4);
      setState(131);
      antlrcpp::downCast<StmtContext *>(_localctx)->e2 = expropt();
      setState(132);
      match(MiniCParser::T__4);
      setState(133);
      antlrcpp::downCast<StmtContext *>(_localctx)->e3 = expropt();
      setState(134);
      match(MiniCParser::T__3);
      setState(135);
      antlrcpp::downCast<StmtContext *>(_localctx)->stmtContext = stmt();

              antlrcpp::downCast<StmtContext *>(_localctx)->val =  new minicc::ForStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->e1->val);
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->e2->val);
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->e3->val);
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->stmtContext->val);
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(138);
      match(MiniCParser::T__10);
      setState(139);
      match(MiniCParser::T__2);
      setState(140);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(141);
      match(MiniCParser::T__3);
      setState(142);
      antlrcpp::downCast<StmtContext *>(_localctx)->stmtContext = stmt();

              antlrcpp::downCast<StmtContext *>(_localctx)->val =  new minicc::WhileStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->val);
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->stmtContext->val);
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(145);
      match(MiniCParser::T__11);
      setState(146);
      match(MiniCParser::T__4);

              antlrcpp::downCast<StmtContext *>(_localctx)->val =  new minicc::BreakStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(148);
      match(MiniCParser::T__12);
      setState(149);
      match(MiniCParser::T__4);

              antlrcpp::downCast<StmtContext *>(_localctx)->val =  new minicc::ReturnStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(151);
      match(MiniCParser::T__12);
      setState(152);
      antlrcpp::downCast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(153);
      match(MiniCParser::T__4);

              antlrcpp::downCast<StmtContext *>(_localctx)->val =  new minicc::ReturnStatement();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<StmtContext *>(_localctx)->exprContext->val);
          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(156);
      antlrcpp::downCast<StmtContext *>(_localctx)->scopeContext = scope();

              antlrcpp::downCast<StmtContext *>(_localctx)->val =  antlrcpp::downCast<StmtContext *>(_localctx)->scopeContext->val;
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarlistContext ------------------------------------------------------------------

MiniCParser::VarlistContext::VarlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VarlistentryContext* MiniCParser::VarlistContext::varlistentry() {
  return getRuleContext<MiniCParser::VarlistentryContext>(0);
}

MiniCParser::VarlistContext* MiniCParser::VarlistContext::varlist() {
  return getRuleContext<MiniCParser::VarlistContext>(0);
}


size_t MiniCParser::VarlistContext::getRuleIndex() const {
  return MiniCParser::RuleVarlist;
}

void MiniCParser::VarlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarlist(this);
}

void MiniCParser::VarlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarlist(this);
}


std::any MiniCParser::VarlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVarlist(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::VarlistContext* MiniCParser::varlist() {
   return varlist(0);
}

MiniCParser::VarlistContext* MiniCParser::varlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::VarlistContext *_localctx = _tracker.createInstance<VarlistContext>(_ctx, parentState);
  MiniCParser::VarlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, MiniCParser::RuleVarlist, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(162);
    antlrcpp::downCast<VarlistContext *>(_localctx)->varlistentryContext = varlistentry();

            _localctx->val.clear();
            _localctx->val.push_back(antlrcpp::downCast<VarlistContext *>(_localctx)->varlistentryContext->val);
        
    _ctx->stop = _input->LT(-1);
    setState(172);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<VarlistContext>(parentContext, parentState);
        _localctx->v1 = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleVarlist);
        setState(165);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(166);
        match(MiniCParser::T__13);
        setState(167);
        antlrcpp::downCast<VarlistContext *>(_localctx)->varlistentryContext = varlistentry();

                          antlrcpp::downCast<VarlistContext *>(_localctx)->val =  antlrcpp::downCast<VarlistContext *>(_localctx)->v1->val;
                          _localctx->val.push_back(antlrcpp::downCast<VarlistContext *>(_localctx)->varlistentryContext->val);
                       
      }
      setState(174);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarlistentryContext ------------------------------------------------------------------

MiniCParser::VarlistentryContext::VarlistentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VarnameContext* MiniCParser::VarlistentryContext::varname() {
  return getRuleContext<MiniCParser::VarnameContext>(0);
}

tree::TerminalNode* MiniCParser::VarlistentryContext::INT() {
  return getToken(MiniCParser::INT, 0);
}


size_t MiniCParser::VarlistentryContext::getRuleIndex() const {
  return MiniCParser::RuleVarlistentry;
}

void MiniCParser::VarlistentryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarlistentry(this);
}

void MiniCParser::VarlistentryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarlistentry(this);
}


std::any MiniCParser::VarlistentryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVarlistentry(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VarlistentryContext* MiniCParser::varlistentry() {
  VarlistentryContext *_localctx = _tracker.createInstance<VarlistentryContext>(_ctx, getState());
  enterRule(_localctx, 14, MiniCParser::RuleVarlistentry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(184);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(175);
      antlrcpp::downCast<VarlistentryContext *>(_localctx)->varnameContext = varname();

              antlrcpp::downCast<VarlistentryContext *>(_localctx)->val =  new minicc::VarReference();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<VarlistentryContext *>(_localctx)->varnameContext->val);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(178);
      antlrcpp::downCast<VarlistentryContext *>(_localctx)->varnameContext = varname();
      setState(179);
      match(MiniCParser::T__14);
      setState(180);
      antlrcpp::downCast<VarlistentryContext *>(_localctx)->intToken = match(MiniCParser::INT);
      setState(181);
      match(MiniCParser::T__15);

              antlrcpp::downCast<VarlistentryContext *>(_localctx)->val =  new minicc::VarReference();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<VarlistentryContext *>(_localctx)->varnameContext->val);
              antlrcpp::downCast<VarlistentryContext *>(_localctx)->tmp =  minicc::ConstantLiteralExpr::fromString((antlrcpp::downCast<VarlistentryContext *>(_localctx)->intToken != nullptr ? antlrcpp::downCast<VarlistentryContext *>(_localctx)->intToken->getText() : ""));
              _localctx->tmp->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(_localctx->tmp);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VartypeContext ------------------------------------------------------------------

MiniCParser::VartypeContext::VartypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::VartypeContext::getRuleIndex() const {
  return MiniCParser::RuleVartype;
}

void MiniCParser::VartypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVartype(this);
}

void MiniCParser::VartypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVartype(this);
}


std::any MiniCParser::VartypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVartype(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VartypeContext* MiniCParser::vartype() {
  VartypeContext *_localctx = _tracker.createInstance<VartypeContext>(_ctx, getState());
  enterRule(_localctx, 16, MiniCParser::RuleVartype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(192);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__16: {
        enterOuterAlt(_localctx, 1);
        setState(186);
        match(MiniCParser::T__16);

                antlrcpp::downCast<VartypeContext *>(_localctx)->val =  new minicc::TypeReference(minicc::Type::Int);
                _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case MiniCParser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(188);
        match(MiniCParser::T__17);

                antlrcpp::downCast<VartypeContext *>(_localctx)->val =  new minicc::TypeReference(minicc::Type::Bool);
                _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case MiniCParser::T__18: {
        enterOuterAlt(_localctx, 3);
        setState(190);
        match(MiniCParser::T__18);

                antlrcpp::downCast<VartypeContext *>(_localctx)->val =  new minicc::TypeReference(minicc::Type::Char);
                _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RettypeContext ------------------------------------------------------------------

MiniCParser::RettypeContext::RettypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::RettypeContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}


size_t MiniCParser::RettypeContext::getRuleIndex() const {
  return MiniCParser::RuleRettype;
}

void MiniCParser::RettypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRettype(this);
}

void MiniCParser::RettypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRettype(this);
}


std::any MiniCParser::RettypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitRettype(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::RettypeContext* MiniCParser::rettype() {
  RettypeContext *_localctx = _tracker.createInstance<RettypeContext>(_ctx, getState());
  enterRule(_localctx, 18, MiniCParser::RuleRettype);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(199);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__19: {
        enterOuterAlt(_localctx, 1);
        setState(194);
        match(MiniCParser::T__19);

                antlrcpp::downCast<RettypeContext *>(_localctx)->val =  new minicc::TypeReference(minicc::Type::Void);
                _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case MiniCParser::T__16:
      case MiniCParser::T__17:
      case MiniCParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(196);
        antlrcpp::downCast<RettypeContext *>(_localctx)->vartypeContext = vartype();

                antlrcpp::downCast<RettypeContext *>(_localctx)->val =  antlrcpp::downCast<RettypeContext *>(_localctx)->vartypeContext->val;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

MiniCParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ParameterlistContext* MiniCParser::ParametersContext::parameterlist() {
  return getRuleContext<MiniCParser::ParameterlistContext>(0);
}


size_t MiniCParser::ParametersContext::getRuleIndex() const {
  return MiniCParser::RuleParameters;
}

void MiniCParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void MiniCParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}


std::any MiniCParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ParametersContext* MiniCParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 20, MiniCParser::RuleParameters);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(205);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__3: {
        enterOuterAlt(_localctx, 1);

                _localctx->val.clear();
            
        break;
      }

      case MiniCParser::T__16:
      case MiniCParser::T__17:
      case MiniCParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(202);
        antlrcpp::downCast<ParametersContext *>(_localctx)->parameterlistContext = parameterlist(0);

                antlrcpp::downCast<ParametersContext *>(_localctx)->val =  antlrcpp::downCast<ParametersContext *>(_localctx)->parameterlistContext->val;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterlistContext ------------------------------------------------------------------

MiniCParser::ParameterlistContext::ParameterlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ParameterentryContext* MiniCParser::ParameterlistContext::parameterentry() {
  return getRuleContext<MiniCParser::ParameterentryContext>(0);
}

MiniCParser::ParameterlistContext* MiniCParser::ParameterlistContext::parameterlist() {
  return getRuleContext<MiniCParser::ParameterlistContext>(0);
}


size_t MiniCParser::ParameterlistContext::getRuleIndex() const {
  return MiniCParser::RuleParameterlist;
}

void MiniCParser::ParameterlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterlist(this);
}

void MiniCParser::ParameterlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterlist(this);
}


std::any MiniCParser::ParameterlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParameterlist(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::ParameterlistContext* MiniCParser::parameterlist() {
   return parameterlist(0);
}

MiniCParser::ParameterlistContext* MiniCParser::parameterlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ParameterlistContext *_localctx = _tracker.createInstance<ParameterlistContext>(_ctx, parentState);
  MiniCParser::ParameterlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, MiniCParser::RuleParameterlist, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(208);
    antlrcpp::downCast<ParameterlistContext *>(_localctx)->parameterentryContext = parameterentry();

            _localctx->val.clear();
            _localctx->val.push_back(antlrcpp::downCast<ParameterlistContext *>(_localctx)->parameterentryContext->val);
        
    _ctx->stop = _input->LT(-1);
    setState(218);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterlistContext>(parentContext, parentState);
        _localctx->p1 = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleParameterlist);
        setState(211);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(212);
        match(MiniCParser::T__13);
        setState(213);
        antlrcpp::downCast<ParameterlistContext *>(_localctx)->parameterentryContext = parameterentry();

                          antlrcpp::downCast<ParameterlistContext *>(_localctx)->val = antlrcpp::downCast<ParameterlistContext *>(_localctx)->p1->val;
                          _localctx->val.push_back(antlrcpp::downCast<ParameterlistContext *>(_localctx)->parameterentryContext->val);
                       
      }
      setState(220);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterentryContext ------------------------------------------------------------------

MiniCParser::ParameterentryContext::ParameterentryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VartypeContext* MiniCParser::ParameterentryContext::vartype() {
  return getRuleContext<MiniCParser::VartypeContext>(0);
}

MiniCParser::ParameternameContext* MiniCParser::ParameterentryContext::parametername() {
  return getRuleContext<MiniCParser::ParameternameContext>(0);
}


size_t MiniCParser::ParameterentryContext::getRuleIndex() const {
  return MiniCParser::RuleParameterentry;
}

void MiniCParser::ParameterentryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterentry(this);
}

void MiniCParser::ParameterentryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterentry(this);
}


std::any MiniCParser::ParameterentryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParameterentry(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ParameterentryContext* MiniCParser::parameterentry() {
  ParameterentryContext *_localctx = _tracker.createInstance<ParameterentryContext>(_ctx, getState());
  enterRule(_localctx, 24, MiniCParser::RuleParameterentry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    antlrcpp::downCast<ParameterentryContext *>(_localctx)->vartypeContext = vartype();
    setState(222);
    antlrcpp::downCast<ParameterentryContext *>(_localctx)->parameternameContext = parametername();

            antlrcpp::downCast<ParameterentryContext *>(_localctx)->val =  new minicc::Parameter();
            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            _localctx->val->addChild(antlrcpp::downCast<ParameterentryContext *>(_localctx)->vartypeContext->val);
            _localctx->val->addChild(antlrcpp::downCast<ParameterentryContext *>(_localctx)->parameternameContext->val);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExproptContext ------------------------------------------------------------------

MiniCParser::ExproptContext::ExproptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::ExproptContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}


size_t MiniCParser::ExproptContext::getRuleIndex() const {
  return MiniCParser::RuleExpropt;
}

void MiniCParser::ExproptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpropt(this);
}

void MiniCParser::ExproptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpropt(this);
}


std::any MiniCParser::ExproptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpropt(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ExproptContext* MiniCParser::expropt() {
  ExproptContext *_localctx = _tracker.createInstance<ExproptContext>(_ctx, getState());
  enterRule(_localctx, 26, MiniCParser::RuleExpropt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(229);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__2:
      case MiniCParser::T__20:
      case MiniCParser::T__30:
      case MiniCParser::T__34:
      case MiniCParser::T__35:
      case MiniCParser::ID:
      case MiniCParser::INT:
      case MiniCParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(225);
        antlrcpp::downCast<ExproptContext *>(_localctx)->exprContext = expr(0);

                antlrcpp::downCast<ExproptContext *>(_localctx)->val =  antlrcpp::downCast<ExproptContext *>(_localctx)->exprContext->val;
            
        break;
      }

      case MiniCParser::T__3:
      case MiniCParser::T__4: {
        enterOuterAlt(_localctx, 2);

                antlrcpp::downCast<ExproptContext *>(_localctx)->val =  nullptr;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MiniCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ExprContext::INT() {
  return getToken(MiniCParser::INT, 0);
}

tree::TerminalNode* MiniCParser::ExprContext::CHAR() {
  return getToken(MiniCParser::CHAR, 0);
}

std::vector<MiniCParser::ExprContext *> MiniCParser::ExprContext::expr() {
  return getRuleContexts<MiniCParser::ExprContext>();
}

MiniCParser::ExprContext* MiniCParser::ExprContext::expr(size_t i) {
  return getRuleContext<MiniCParser::ExprContext>(i);
}

MiniCParser::VarContext* MiniCParser::ExprContext::var() {
  return getRuleContext<MiniCParser::VarContext>(0);
}

MiniCParser::FuncnameContext* MiniCParser::ExprContext::funcname() {
  return getRuleContext<MiniCParser::FuncnameContext>(0);
}

MiniCParser::ArgumentsContext* MiniCParser::ExprContext::arguments() {
  return getRuleContext<MiniCParser::ArgumentsContext>(0);
}

MiniCParser::ParameternameContext* MiniCParser::ExprContext::parametername() {
  return getRuleContext<MiniCParser::ParameternameContext>(0);
}


size_t MiniCParser::ExprContext::getRuleIndex() const {
  return MiniCParser::RuleExpr;
}

void MiniCParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void MiniCParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any MiniCParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::ExprContext* MiniCParser::expr() {
   return expr(0);
}

MiniCParser::ExprContext* MiniCParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MiniCParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, MiniCParser::RuleExpr, precedence);

    antlrcpp::downCast<ExprContext *>(_localctx)->minus_flag = false; antlrcpp::downCast<ExprContext *>(_localctx)->compare = false;
    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(270);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(232);
      antlrcpp::downCast<ExprContext *>(_localctx)->intToken = match(MiniCParser::INT);

              antlrcpp::downCast<ExprContext *>(_localctx)->val =  minicc::ConstantLiteralExpr::fromString((antlrcpp::downCast<ExprContext *>(_localctx)->intToken != nullptr ? antlrcpp::downCast<ExprContext *>(_localctx)->intToken->getText() : ""));
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      setState(234);
      antlrcpp::downCast<ExprContext *>(_localctx)->charToken = match(MiniCParser::CHAR);

              antlrcpp::downCast<ExprContext *>(_localctx)->val =  minicc::ConstantLiteralExpr::fromString((antlrcpp::downCast<ExprContext *>(_localctx)->charToken != nullptr ? antlrcpp::downCast<ExprContext *>(_localctx)->charToken->getText() : ""));
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 3: {
      setState(236);
      match(MiniCParser::T__20);
      setState(237);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(14);

              antlrcpp::downCast<ExprContext *>(_localctx)->minus_flag =  true;
              if (typeid(*antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->val) == typeid(minicc::IntLiteralExpr)){
                  delete antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->val;
                  antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->val = minicc::ConstantLiteralExpr::fromString((antlrcpp::downCast<ExprContext *>(_localctx)->exprContext != nullptr ? _input->getText(antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->start, antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->stop) : nullptr), _localctx->minus_flag);
                  antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine()); 
              }
              antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::UnaryExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              ((minicc::UnaryExpr*)_localctx->val)->setOpcode(minicc::Expr::Sub);
              _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->val);
          
      break;
    }

    case 4: {
      setState(240);
      match(MiniCParser::T__30);
      setState(241);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(10);

              antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::UnaryExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              ((minicc::UnaryExpr*)_localctx->val)->setOpcode(minicc::Expr::Not);
              _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->val);
          
      break;
    }

    case 5: {
      setState(244);
      antlrcpp::downCast<ExprContext *>(_localctx)->varContext = var();
      setState(245);
      match(MiniCParser::T__33);
      setState(246);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(7);

              antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::AssignmentExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->varContext->val);
              _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->val);
          
      break;
    }

    case 6: {
      setState(249);
      match(MiniCParser::T__34);

              antlrcpp::downCast<ExprContext *>(_localctx)->val =  minicc::ConstantLiteralExpr::fromString("true");
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 7: {
      setState(251);
      match(MiniCParser::T__35);

              antlrcpp::downCast<ExprContext *>(_localctx)->val =  minicc::ConstantLiteralExpr::fromString("false");
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 8: {
      setState(253);
      match(MiniCParser::T__2);
      setState(254);
      antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(255);
      match(MiniCParser::T__3);

              antlrcpp::downCast<ExprContext *>(_localctx)->val =  antlrcpp::downCast<ExprContext *>(_localctx)->exprContext->val;
          
      break;
    }

    case 9: {
      setState(258);
      antlrcpp::downCast<ExprContext *>(_localctx)->varContext = var();

              antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::VarExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->varContext->val);
          
      break;
    }

    case 10: {
      setState(261);
      antlrcpp::downCast<ExprContext *>(_localctx)->funcnameContext = funcname();
      setState(262);
      match(MiniCParser::T__2);
      setState(263);
      antlrcpp::downCast<ExprContext *>(_localctx)->argumentsContext = arguments();
      setState(264);
      match(MiniCParser::T__3);

              antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::CallExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->funcnameContext->val);
              for (size_t i = 0; i < antlrcpp::downCast<ExprContext *>(_localctx)->argumentsContext->val.size(); i++)
                  _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->argumentsContext->val[i]);
          
      break;
    }

    case 11: {
      setState(267);
      antlrcpp::downCast<ExprContext *>(_localctx)->parameternameContext = parametername();

              antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::VarExpr();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              antlrcpp::downCast<ExprContext *>(_localctx)->tmp =  new minicc::VarReference();
              _localctx->tmp->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->tmp->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->parameternameContext->val);
              _localctx->val->addChild(_localctx->tmp);
          
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(299);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(297);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(272);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(273);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MiniCParser::T__21

          || _la == MiniCParser::T__22)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(274);
          antlrcpp::downCast<ExprContext *>(_localctx)->e2 = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(14);

                            antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::BinaryExpr();
                            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            ((minicc::BinaryExpr*)_localctx->val)->setOpcode(minicc::Expr::opcodeFromString((antlrcpp::downCast<ExprContext *>(_localctx)->op != nullptr ? antlrcpp::downCast<ExprContext *>(_localctx)->op->getText() : "")));
                            _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->e1->val);
                            _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->e2->val);
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(277);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(278);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MiniCParser::T__20

          || _la == MiniCParser::T__23)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(279);
          antlrcpp::downCast<ExprContext *>(_localctx)->e2 = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(13);

                            antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::BinaryExpr();
                            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            ((minicc::BinaryExpr*)_localctx->val)->setOpcode(minicc::Expr::opcodeFromString((antlrcpp::downCast<ExprContext *>(_localctx)->op != nullptr ? antlrcpp::downCast<ExprContext *>(_localctx)->op->getText() : "")));
                            _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->e1->val);
                            _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->e2->val);
                        
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(282);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(283);
          antlrcpp::downCast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 2113929216) != 0)) {
            antlrcpp::downCast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(284);
          antlrcpp::downCast<ExprContext *>(_localctx)->e2 = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(12);

                            antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::BinaryExpr();
                            antlrcpp::downCast<ExprContext *>(_localctx)->compare =  true;
                            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            ((minicc::BinaryExpr*)_localctx->val)->setOpcode(minicc::Expr::opcodeFromString((antlrcpp::downCast<ExprContext *>(_localctx)->op != nullptr ? antlrcpp::downCast<ExprContext *>(_localctx)->op->getText() : "")));
                            _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->e1->val);
                            _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->e2->val);
                        
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(287);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(288);
          match(MiniCParser::T__31);
          setState(289);
          antlrcpp::downCast<ExprContext *>(_localctx)->e2 = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(10);

                            antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::BinaryExpr();
                            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            ((minicc::BinaryExpr*)_localctx->val)->setOpcode(minicc::Expr::And);
                            _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->e1->val);
                            _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->e2->val);
                        
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->e1 = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(292);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(293);
          match(MiniCParser::T__32);
          setState(294);
          antlrcpp::downCast<ExprContext *>(_localctx)->e2 = antlrcpp::downCast<ExprContext *>(_localctx)->exprContext = expr(9);

                            antlrcpp::downCast<ExprContext *>(_localctx)->val =  new minicc::BinaryExpr();
                            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            ((minicc::BinaryExpr*)_localctx->val)->setOpcode(minicc::Expr::Or);
                            _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->e1->val);
                            _localctx->val->addChild(antlrcpp::downCast<ExprContext *>(_localctx)->e2->val);
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(301);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

MiniCParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::VarnameContext* MiniCParser::VarContext::varname() {
  return getRuleContext<MiniCParser::VarnameContext>(0);
}

MiniCParser::ExprContext* MiniCParser::VarContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}


size_t MiniCParser::VarContext::getRuleIndex() const {
  return MiniCParser::RuleVar;
}

void MiniCParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void MiniCParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


std::any MiniCParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VarContext* MiniCParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 30, MiniCParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(311);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(302);
      antlrcpp::downCast<VarContext *>(_localctx)->varnameContext = varname();

              antlrcpp::downCast<VarContext *>(_localctx)->val =  new minicc::VarReference();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<VarContext *>(_localctx)->varnameContext->val);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(305);
      antlrcpp::downCast<VarContext *>(_localctx)->varnameContext = varname();
      setState(306);
      match(MiniCParser::T__14);
      setState(307);
      antlrcpp::downCast<VarContext *>(_localctx)->exprContext = expr(0);
      setState(308);
      match(MiniCParser::T__15);

              antlrcpp::downCast<VarContext *>(_localctx)->val =  new minicc::VarReference();
              _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->val->addChild(antlrcpp::downCast<VarContext *>(_localctx)->varnameContext->val);
              _localctx->val->addChild(antlrcpp::downCast<VarContext *>(_localctx)->exprContext->val);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

MiniCParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ArgumentlistContext* MiniCParser::ArgumentsContext::argumentlist() {
  return getRuleContext<MiniCParser::ArgumentlistContext>(0);
}


size_t MiniCParser::ArgumentsContext::getRuleIndex() const {
  return MiniCParser::RuleArguments;
}

void MiniCParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void MiniCParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


std::any MiniCParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ArgumentsContext* MiniCParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 32, MiniCParser::RuleArguments);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::T__3: {
        enterOuterAlt(_localctx, 1);

                _localctx->val.clear();
            
        break;
      }

      case MiniCParser::T__2:
      case MiniCParser::T__20:
      case MiniCParser::T__30:
      case MiniCParser::T__34:
      case MiniCParser::T__35:
      case MiniCParser::ID:
      case MiniCParser::INT:
      case MiniCParser::CHAR: {
        enterOuterAlt(_localctx, 2);
        setState(314);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->argumentlistContext = argumentlist(0);

                antlrcpp::downCast<ArgumentsContext *>(_localctx)->val =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->argumentlistContext->val;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentlistContext ------------------------------------------------------------------

MiniCParser::ArgumentlistContext::ArgumentlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::ExprContext* MiniCParser::ArgumentlistContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

MiniCParser::ArgumentlistContext* MiniCParser::ArgumentlistContext::argumentlist() {
  return getRuleContext<MiniCParser::ArgumentlistContext>(0);
}


size_t MiniCParser::ArgumentlistContext::getRuleIndex() const {
  return MiniCParser::RuleArgumentlist;
}

void MiniCParser::ArgumentlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentlist(this);
}

void MiniCParser::ArgumentlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentlist(this);
}


std::any MiniCParser::ArgumentlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitArgumentlist(this);
  else
    return visitor->visitChildren(this);
}


MiniCParser::ArgumentlistContext* MiniCParser::argumentlist() {
   return argumentlist(0);
}

MiniCParser::ArgumentlistContext* MiniCParser::argumentlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::ArgumentlistContext *_localctx = _tracker.createInstance<ArgumentlistContext>(_ctx, parentState);
  MiniCParser::ArgumentlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, MiniCParser::RuleArgumentlist, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(320);
    antlrcpp::downCast<ArgumentlistContext *>(_localctx)->exprContext = expr(0);

            _localctx->val.clear();
            _localctx->val.push_back(antlrcpp::downCast<ArgumentlistContext *>(_localctx)->exprContext->val);
        
    _ctx->stop = _input->LT(-1);
    setState(330);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentlistContext>(parentContext, parentState);
        _localctx->a1 = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArgumentlist);
        setState(323);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(324);
        match(MiniCParser::T__13);
        setState(325);
        antlrcpp::downCast<ArgumentlistContext *>(_localctx)->exprContext = expr(0);

                          antlrcpp::downCast<ArgumentlistContext *>(_localctx)->val = antlrcpp::downCast<ArgumentlistContext *>(_localctx)->a1->val;
                          _localctx->val.push_back(antlrcpp::downCast<ArgumentlistContext *>(_localctx)->exprContext->val);
                       
      }
      setState(332);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarnameContext ------------------------------------------------------------------

MiniCParser::VarnameContext::VarnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::VarnameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::VarnameContext::getRuleIndex() const {
  return MiniCParser::RuleVarname;
}

void MiniCParser::VarnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarname(this);
}

void MiniCParser::VarnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarname(this);
}


std::any MiniCParser::VarnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVarname(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::VarnameContext* MiniCParser::varname() {
  VarnameContext *_localctx = _tracker.createInstance<VarnameContext>(_ctx, getState());
  enterRule(_localctx, 36, MiniCParser::RuleVarname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    antlrcpp::downCast<VarnameContext *>(_localctx)->idToken = match(MiniCParser::ID);

            antlrcpp::downCast<VarnameContext *>(_localctx)->val =  new minicc::Identifier((antlrcpp::downCast<VarnameContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<VarnameContext *>(_localctx)->idToken->getText() : ""));
            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncnameContext ------------------------------------------------------------------

MiniCParser::FuncnameContext::FuncnameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::FuncnameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::FuncnameContext::getRuleIndex() const {
  return MiniCParser::RuleFuncname;
}

void MiniCParser::FuncnameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncname(this);
}

void MiniCParser::FuncnameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncname(this);
}


std::any MiniCParser::FuncnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitFuncname(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::FuncnameContext* MiniCParser::funcname() {
  FuncnameContext *_localctx = _tracker.createInstance<FuncnameContext>(_ctx, getState());
  enterRule(_localctx, 38, MiniCParser::RuleFuncname);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    antlrcpp::downCast<FuncnameContext *>(_localctx)->idToken = match(MiniCParser::ID);

            antlrcpp::downCast<FuncnameContext *>(_localctx)->val =  new minicc::Identifier((antlrcpp::downCast<FuncnameContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<FuncnameContext *>(_localctx)->idToken->getText() : ""));
            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameternameContext ------------------------------------------------------------------

MiniCParser::ParameternameContext::ParameternameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ParameternameContext::ID() {
  return getToken(MiniCParser::ID, 0);
}


size_t MiniCParser::ParameternameContext::getRuleIndex() const {
  return MiniCParser::RuleParametername;
}

void MiniCParser::ParameternameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParametername(this);
}

void MiniCParser::ParameternameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MiniCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParametername(this);
}


std::any MiniCParser::ParameternameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitParametername(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ParameternameContext* MiniCParser::parametername() {
  ParameternameContext *_localctx = _tracker.createInstance<ParameternameContext>(_ctx, getState());
  enterRule(_localctx, 40, MiniCParser::RuleParametername);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    antlrcpp::downCast<ParameternameContext *>(_localctx)->idToken = match(MiniCParser::ID);

            antlrcpp::downCast<ParameternameContext *>(_localctx)->val =  new minicc::Identifier((antlrcpp::downCast<ParameternameContext *>(_localctx)->idToken != nullptr ? antlrcpp::downCast<ParameternameContext *>(_localctx)->idToken->getText() : ""));
            _localctx->val->setSrcLoc(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MiniCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return varlistSempred(antlrcpp::downCast<VarlistContext *>(context), predicateIndex);
    case 11: return parameterlistSempred(antlrcpp::downCast<ParameterlistContext *>(context), predicateIndex);
    case 14: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 17: return argumentlistSempred(antlrcpp::downCast<ArgumentlistContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MiniCParser::varlistSempred(VarlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::parameterlistSempred(ParameterlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MiniCParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 9);
    case 6: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

bool MiniCParser::argumentlistSempred(ArgumentlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void MiniCParser::initialize() {
  ::antlr4::internal::call_once(minicParserOnceFlag, minicParserInitialize);
}
