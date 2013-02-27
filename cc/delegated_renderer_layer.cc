// Copyright 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cc/delegated_renderer_layer.h"

#include "cc/delegated_renderer_layer_impl.h"

namespace cc {

scoped_refptr<DelegatedRendererLayer> DelegatedRendererLayer::Create() {
  return scoped_refptr<DelegatedRendererLayer>(new DelegatedRendererLayer());
}

DelegatedRendererLayer::DelegatedRendererLayer()
    : Layer() {
}

DelegatedRendererLayer::~DelegatedRendererLayer() {}

scoped_ptr<LayerImpl> DelegatedRendererLayer::createLayerImpl(
    LayerTreeImpl* tree_impl) {
  return DelegatedRendererLayerImpl::Create(
      tree_impl, m_layerId).PassAs<LayerImpl>();
}

void DelegatedRendererLayer::pushPropertiesTo(LayerImpl* impl) {
  Layer::pushPropertiesTo(impl);

  DelegatedRendererLayerImpl* delegated_impl =
      static_cast<DelegatedRendererLayerImpl*>(impl);
  delegated_impl->CreateChildIdIfNeeded();
}

}  // namespace cc
