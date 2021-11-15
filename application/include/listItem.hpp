#pragma once

#include <borealis.hpp>
#include <string>

struct ListItem : public brls::Box
{
    ListItem();

    void draw(NVGcontext* vg, float x, float y, float width, float height, brls::Style style, brls::FrameContext* ctx) override;

    static brls::View* create();

    private:
    BRLS_BIND(brls::Image, thumbnail, "thumbnail");
    BRLS_BIND(brls::Label, label, "label");
    BRLS_BIND(brls::Label, value, "value");
};