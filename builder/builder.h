#pragma once

#include <iostream>
#include <string>
#include <algorithm>

class ASCIIConverter {
protected:
    struct Tag {
        std::string tagName = "";
        std::string content = "";
        Tag(const std::string& n, const std::string& c) : tagName(n), content(c) {}
    };
    Tag extractTag(const std::string& tag) {
        auto firstClosed = tag.find('>');
        auto firstOpen = tag.find('<');
        auto secondOpen = tag.find_last_of('<');

        auto tagContents = tag.substr(firstClosed + 1, secondOpen-firstClosed-1);
        auto tagName = tag.substr(firstOpen + 1, firstClosed-firstOpen -1);

        return Tag(tagName, tagContents);
    }
public:
    virtual std::string parseTag(const std::string& tag) = 0;
    virtual std::string parseNotTag(const std::string& tag) {
        return tag;
    }
};

class WithoutTags : public ASCIIConverter {
public:
    virtual std::string parseTag(const std::string& tag) {
        auto t = extractTag(tag);

        return t.content;
    };
};

class UpperCase : public ASCIIConverter {
public:
    virtual std::string parseTag(const std::string& tag) {
        auto t = extractTag(tag);

        std::transform(t.content.begin(), t.content.end(),t.content.begin(), ::toupper);
        return t.content;
    };
};

class UpperCaseLeaveTag : public ASCIIConverter {
public:
    virtual std::string parseTag(const std::string& tag) {
        auto t = extractTag(tag);

        std::transform(t.content.begin(), t.content.end(),t.content.begin(), ::toupper);
        return "<" + t.tagName + ">" + t.content + "</" + t.tagName + ">";
    };
};


class WeirdTag : public ASCIIConverter {
public:
    virtual std::string parseTag(const std::string& tag) {
        auto t = extractTag(tag);

        return "{" + t.tagName + "#" + t.content + "}";
    };
};


class HTMLReader {
private:
    ASCIIConverter& m_converter;
public:
    HTMLReader(ASCIIConverter& converter) : m_converter(converter) {}
    std::string convertInput(const std::string& in) {
        auto pos = 0;
        std::string out = "";
        while (true) {
            auto tagPos = in.find('<', pos);
            auto tagNameClose = in.find('>', pos);
            auto tagClose = in.find('>', tagNameClose + 1);
            if (tagPos != in.npos) {
                out += m_converter.parseNotTag(in.substr(pos, tagPos-pos));
            } else {
                out += m_converter.parseNotTag(in.substr(pos));
            }
            if (tagPos != in.npos) {
                out += m_converter.parseTag(in.substr(tagPos, tagClose-tagPos));
            } else {
                break;
            }
            pos = tagClose + 1;    
        }

        return out;
    }
};