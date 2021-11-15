#include <listItem.hpp>

ListItem::ListItem()
{
    this->inflateFromXMLRes("xml/views/listItem.xml");

    this->forwardXMLAttribute("image", this->thumbnail);
    this->forwardXMLAttribute("label", this->label, "text");
    this->forwardXMLAttribute("value", this->value, "text");
}

void ListItem::draw(NVGcontext* vg, float x, float y, float width, float height, brls::Style style, brls::FrameContext* ctx)
{
    nvgFillColor(vg, View::a(nvgRGB(65, 66, 68)));
    nvgBeginPath(vg);
    nvgRoundedRect(vg, x, y, width, height, 35.0f);
    nvgFill(vg); 

    thumbnail->frame(ctx);
    label->frame(ctx);
    value->frame(ctx);
}

brls::View* ListItem::create()
{
    return new ListItem();
}